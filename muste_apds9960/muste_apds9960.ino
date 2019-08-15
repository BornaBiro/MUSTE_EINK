#include "page1.c"
#include "page2.c"
#include "page3.c"
#include "page4.c"
#include "page5.c"
#include "page6.c"
#include "page7.c"
#include "page8.c"

const uint8_t* p[] = {image_data_page1, image_data_page2, image_data_page3, image_data_page4, image_data_page5, image_data_page6, image_data_page7, image_data_page8};

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "E_INK.h"
#include <SparkFun_APDS9960.h>
eink display;
SparkFun_APDS9960 apds = SparkFun_APDS9960();

void setup() {
  Wire.begin();
  display.begin();
  display.setRotation(2);
  apds.init();
  apds.enableGestureSensor(true);
  display.setTextSize(2);
  refresh();
}


int8_t page = 0;
void loop() {
  if ( apds.isGestureAvailable() ) {
    switch ( apds.readGesture() ) {
      case DIR_UP:
        page = 7;
        refresh();
        break;
      case DIR_DOWN:
        page = 0;
        refresh();
        break;
      case DIR_LEFT:
        page--;
        if (page < 0) page = 7;
        refresh();
        break;
      case DIR_RIGHT:
        page++;
        if (page > 7) page = 0;
        refresh();
        break;
      case DIR_NEAR:
        Serial.println("NEAR");
        break;
      case DIR_FAR:
        Serial.println("FAR");
        break;
      default:
        Serial.println("NONE");
    }
  }
  delay(100);
}

void refresh() {
  //display.einkOn();
  display.clearDisplay();
  display.drawBitmap(0, 0, p[page], 800, 600, BLACK);
  display.setCursor(0, 0);
  display.print("Page number:");
  display.print(page + 1, DEC);
  display.print("/8");
  display.display();
  //display.einkOff();
}
