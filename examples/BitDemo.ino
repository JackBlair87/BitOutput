#include <BitOutput.h>

void setup() {
  //most significant bit on pin 13
  BitOutput b = BitOutput(2, 1.0, true);
  b.begin();
}
