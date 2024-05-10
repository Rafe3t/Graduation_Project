
#include <SPI.h>

// Define pin connections & motor's steps per revolution
 


volatile int SPI_flag=0;
volatile int SPI_receive=0 ;


/*******************************************SPI GLOBAL VARIABLE*************************************************/
uint8_t Data_2_ToSend = 100;
uint8_t  Data_1_ToSend = 200;
/*************************************************************************************************************/

// Define pin numbers
//const int switchPin = PIN_A0; // Pin connected to the switch
const int ledPin = 7;   // Pin connected to the LED

// SPI settings
const int slaveSelectPin = 9; // Pin connected to the slave select (SS) of the SPI device

void setup() {
  // Initialize SPI
  SPI.begin();
  //SPISettings(7000000, MSBFIRST, SPI_MODE0);
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
    sendSPI(Data_1_ToSend);
    delay(500); // it is necessary for spi double sending
    sendSPI(100);
    
    // Turn on LED
    //digitalWrite(ledPin, HIGH);
    
    // Delay to debounce the switch
    //delay(300);
  
  
    // Turn off LED if the switch is not pressed
    //digitalWrite(ledPin, LOW);
    //delay(300);
}

// Function to send data via SPI
void sendSPI(uint8_t data)
 {
  digitalWrite(slaveSelectPin, LOW); // Select the slave device
  
  // Send data over SPI
  SPI.transfer(data);
  //SPI.transfer(data >> 8); // Send the most significant byte
  //SPI.transfer(data & 0xFF); // Send the least significant byte
  
  digitalWrite(slaveSelectPin, HIGH); // Deselect the slave device
}
/******************************************************SPI ISR****************************************/


/******************************************************SPI ISR END*************************************/
 
