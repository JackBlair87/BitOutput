// -----
// BitOutput.h
// This class is implemented for use with the Arduino environment.
// Created by Jack Blair
// -----

#include "Arduino.h"
#include "BitOutput.h"

// ----- Initialization and Default Values -----

BitOutput::BitOutput(int pinCount, double newDelay, boolean willPrint) {
  numPins = pinCount;
  delayTime = newDelay;
  print = willPrint;

  value = 0;

  Serial.begin(9600);
} 

void BitOutput::begin() {
  int pins[12] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
  for(int x = 0; x < numPins; x++){
    pinMode(pins[x], OUTPUT);
  }

  delay(500);

  while(true){
    value++;
    value = value % (int) pow(2, numPins);
    Serial.println(value);

    char str[numPins];
    itoa( value, str, 2 );
    String decimal = (String) str;
    
    while(decimal.length() != numPins){
      decimal = '0' + decimal;
    }

    Serial.println(decimal);
    
    for(int x = 0; x < numPins; x++){
      if(decimal[x] == '1'){
        Serial.println(pins[x]);
        digitalWrite(pins[x], HIGH);
      }
      else{
        digitalWrite(pins[x], LOW);
      }
    }
  delay(delayTime*1000);
  }
}
