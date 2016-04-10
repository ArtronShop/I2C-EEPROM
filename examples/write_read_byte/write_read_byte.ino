/*
   Name: I2CEEPROM
   File: write_read_byte.ino
   Author: IOXhop
   Website: http://www.ioxhop.com/
*/

#include <I2CEEPROM.h>

// Set I2C address to 0x50
I2CEEPROM eep(0x50);

void setup() {
  Serial.begin(9600);
  eep.begin(); // Begin for I2CEEPROM Library
  
  Serial.println("Write !");
  eep.write(0, 199); // Write data 8Bit to I2C EEPROM address 0
  
  delay(10);
}

void loop() {
  Serial.print("Read: ");
  Serial.println(eep.read(0)); // Read data from address 0
  delay(1000);
}