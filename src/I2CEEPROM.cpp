/*
   Name: I2CEEPROM
   File: I2CEEPROM.cpp
   Author: IOXhop
   Website: http://www.ioxhop.com/
*/

#include "I2CEEPROM.h"

I2CEEPROM::I2CEEPROM(int addr) {
	i2c_addr = addr;
}

void I2CEEPROM::begin() {
	Wire.begin();
}

void I2CEEPROM::write(int addr, byte data) {
	runBegin(addr);
	Wire.write(data);
	Wire.endTransmission();
}

byte I2CEEPROM::read(int addr) {
	byte data = 0xFF;
	
    runBegin(addr);
    Wire.endTransmission();
	
    Wire.requestFrom(i2c_addr, 1);
    if (Wire.available())
		data = Wire.read();
    return data;
}

int I2CEEPROM::print(int addr, String text) {
	int len = text.length();
	runBegin(addr);
	Wire.write((len>>8)&0xFF);
	Wire.write(len&0xFF);
	for (int i=0;i<len;i++) {
		Wire.write(text.charAt(i));
	}
	Wire.endTransmission();
	return addr+len+2;
}

String I2CEEPROM::readString(int addr) {
	int len = read(addr)<<8 | read(addr+1);

	runBegin(addr+2);
    Wire.endTransmission();
	
	Wire.requestFrom(i2c_addr, len);
	String buf="";
    while(Wire.available()){
		char c = (char)Wire.read();
		buf += c;
	}
	return buf;
}

void I2CEEPROM::runBegin(int addr) {
	Wire.beginTransmission(i2c_addr);
    Wire.write((addr>>8)&0xFF);
    Wire.write(addr&0xFF);
}