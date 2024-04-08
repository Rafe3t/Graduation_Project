
#include <SPI.h>

// Define pin connections & motor's steps per revolution
 


volatile int SPI_flag=0;
volatile int SPI_receive=0 ;


/*******************************************SPI GLOBAL VARIABLE*************************************************/
uint16_t Data_16_ToSend = 200;
uint8_t  Data_8_ToSend = 200;
/*************************************************************************************************************/

// Define pin numbers
//const int switchPin = PIN_A0; // Pin connected to the switch
const int ledPin = 7;   // Pin connected to the LED

// SPI settings
const int slaveSelectPin = 10; // Pin connected to the slave select (SS) of the SPI device

void setup() {
  // Initialize SPI
  SPI.begin();
  pinMode(slaveSelectPin, OUTPUT);
  
  // Set up switch and LED
//  pinMode(switchPin, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(ledPin, OUTPUT);
  
  // Turn off LED initially
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Check if the switch is pressed
  
    // Send "200" via SPI
    sendSPI(200);
    
    // Turn on LED
    digitalWrite(ledPin, HIGH);
    
    // Delay to debounce the switch
    delay(500);
  
  
    // Turn off LED if the switch is not pressed
    digitalWrite(ledPin, LOW);
    delay(500);
}

// Function to send data via SPI
void sendSPI(int data) {
  digitalWrite(slaveSelectPin, LOW); // Select the slave device
  
  // Send data over SPI
  SPI.transfer(data >> 8); // Send the most significant byte
  SPI.transfer(data & 0xFF); // Send the least significant byte
  
  digitalWrite(slaveSelectPin, HIGH); // Deselect the slave device
}
/******************************************************SPI ISR****************************************/
ISR(SPI_STC_vect)
{
   

  /*
    SPI_receive= SPDR;
    if(SPI_receive == 1)
    {
      /*adptive cruise mode
    }
    else if(SPI_receive ==2)
    {
     /*Auto Parking Mode
    }
    */
}

/******************************************************SPI ISR END*************************************/
 
