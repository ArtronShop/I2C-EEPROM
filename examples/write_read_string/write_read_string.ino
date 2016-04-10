/*
   Name: I2CEEPROM
   File: write_read_string.ino
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
  eep.print(0, "This string in I2C EEPROM."); // Write String to I2C EEPROM start address 0
  
  delay(10);
}

void loop() {
  Serial.print("Read: ");
  Serial.println(eep.readString(0)); // Read string from address 0
  delay(1000);
}