#include <Wire.h>
#include "BMPs.h"
#include "E_INK.h"
eink display;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  delay(100);
  display.begin();
  display.setRotation(2);
  display.drawBitmap(100, 100, muste, 600, 400, BLACK);
  display.einkOn();
  display.display();
  //display.einkOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}
