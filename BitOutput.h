// -----
// BitOutput.h
// This class is implemented for use with the Arduino environment.
// Created by Jack Blair
// -----

#ifndef BitOutput_h
#define BitOutput_h

#include "Arduino.h"

class BitOutput
{
public:
  // ----- Constructor -----
  BitOutput(int pinCount, double newDelay, boolean print);

  void begin();

private:
  int numPins;
  boolean print;

  double delayTime;
  int value;
};

#endif
