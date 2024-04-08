#include <SPI.h>
#include <Plotter.h>

#include <VL53L0X.h> 
#include <Wire.h>
 
// Define pin connections & motor's steps per revolution
 
const int dirPin = 11;
const int stepPin = 10;
const int slaveSelectPin = 10; // Pin connected to the slave select (SS) of the SPI device
  int steps = 0;
int stepDelay=5000;
char toggle = 0;
char toggleDir = 0;
int readPerStep =1;
int i =-1;
int j = 26;

enum quarters {first,second,third,fourth};
enum quarters tofQuarters = first;
//                 0   1     2     3     4     5     6     7     8     9     10    11    12    13    14    15    16    17    18    19    20    21    22    23    24  25
float sin90_0[] = {1,0.998,0.992,0.982,0.968,0.951,0.929,0.904,0.876,0.844,0.809,0.770,0.728,0.684,0.637,0.587,0.535,0.481,0.425,0.368,0.309,0.248,0.187,0.125,0.062,0};

int read;
float rd;
double x,y;

int  gh =0;

Plotter p;
 

VL53L0X tof;

void sendSPI(int data) {
  digitalWrite(slaveSelectPin, LOW); // Select the slave device
  
  // Send data over SPI
  SPI.transfer(data >> 8); // Send the most significant byte
  SPI.transfer(data & 0xFF); // Send the least significant byte
  
  digitalWrite(slaveSelectPin, HIGH); // Deselect the slave device
}
void setup()
{
  //Serial.begin(9600); 

   tof.init();
   tof.setBus(&Wire);

   
   p.Begin();
   p.AddXYGraph("test", 360, "This is x", x, "This is y", y);
    

  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
 
  //clockwise
  digitalWrite(dirPin, HIGH);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 65456;
  TCCR1B |= (1 << CS10)|(1 << CS12);
  TIMSK1 |= (1 << TOIE1); 
  interrupts();

  //tof.
 
 
}
void loop()
{
 
 /*   digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
 */

  //read = tof.readRangeSingleMillimeters();
  
  if(gh==1)
  {
    read = tof.readRangeSingleMillimeters();
    gh=0;
  }
  
}

 
ISR(TIMER1_OVF_vect)                   
{
  TCNT1 = 65456;                               
 
  if(toggle == 0)
  {
    toggle = 1;
    digitalWrite(stepPin, HIGH);
    readPerStep++;
    if(readPerStep == 4)
    {
      //read = tof.readRangeSingleMillimeters();
      gh=1;
      readPerStep = 0;
      if(tofQuarters == first)
      {
        i=i+2;
        j=j-2;
        rd = read* sin90_0[i];
        y = rd* sin90_0[i];
        x = rd* sin90_0[j];
        if(i==25)
        {
          tofQuarters = second;
        }
      }
      else if(tofQuarters == second)
      {
        i=i-2;
        j=j+2;
        rd = read* -sin90_0[i];
        y = rd* -sin90_0[i];
        x = rd* sin90_0[j];
        if(i==0)
        {
          tofQuarters = third;
        }
      }
      else if(tofQuarters == third)
      {
        i=i+2;
        j=j-2;
        rd = read* -sin90_0[i];
        y = rd* -sin90_0[i];
        x = rd* -sin90_0[j];
        if(i==25)
        {
          tofQuarters = fourth;
        }
      }
      else if(tofQuarters == fourth)
      {
        i=i-2;
        j=j+2;
        rd = read* sin90_0[i];
        y = rd* sin90_0[i]*10;  //Y axis in CM
        x = rd* -sin90_0[j]*10;  //X axis in CM
        if(i==0)
        {
          tofQuarters = first;
        }
      }
      p.Plot();
      sendSPI(y); //y axis in CM
      sendSPI(x); //x axis in CM
      //code here ya Maged
      
    } 
    steps++;
  }
  else
  {
    toggle = 0;
    digitalWrite(stepPin, LOW);
  }

   

}

 
 