#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "E_INK.h"
#include "Fonts/FreeSansBold18pt7b.h"
#include "htmlCode.h"

#include "erad.c"
#include "footer.c"
#include "iron.c"
#include "muste.c"
#include "smile.c"

eink display;
WebServer server(80);

const uint16_t xSize[] = {356, 224, 168, 75};
const uint16_t ySize[] = {53, 29, 50, 75};
const uint8_t* pic[] = {image_data_erad, image_data_iron, image_data_muste, image_data_smile};
String txt;
const char* ssid = "MUSTE_EPAPER";
const char* pass = "e-radionica.com";
int xpos = 0;
int ypos = 280;
int xPosPic = 0;
int yPosPic = 280;
String choice = "0";
unsigned long time1 = 0;
uint8_t newData = 0;
IPAddress serverIP;

void setup() {
  Serial.begin(9600);
  display.begin();
  display.setRotation(2);
  WiFi.begin();
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, pass);

  serverIP = WiFi.softAPIP();

  server.on("/", handleRoot);
  server.on("/string/{}", handleString);
  server.begin();
  txt = "Your text can be here! :)\nJust follow instructions^";
  updatePaper();
}

void loop() {
  server.handleClient();

  if (((unsigned long)(millis() - time1) > 2* 60000) && newData == 1) {
    newData = 0;
    txt = "Your text can be here! :)\nJust follow instructions^";
    xpos = 0;
    ypos = 280;
    xPosPic = 0;
    yPosPic = 280;
    choice = "0";
    updatePaper();
  }
}

void updateHTML() {
  String x0, y0;
  server.send(200, "text/html", s);
}

void handleRoot() {
  updateHTML();
}

void handleString() {
  txt = server.arg(0);
  xpos = server.arg(1).toInt();
  ypos = server.arg(2).toInt() + 280;
  choice = server.arg(3);
  xPosPic = server.arg(4).toInt();
  yPosPic = server.arg(5).toInt() + 280;
  if(ypos < 280) xpos = 280;
  if(xPosPic < 280) xpos = 280;
  Serial.println(txt);
  Serial.println(xpos);
  Serial.println(ypos);
  Serial.println(choice.toInt());
  Serial.println(xPosPic);
  Serial.println(yPosPic);
  Serial.println();
  Serial.println((String)(xPosPic));
  //Serial.println(arg2);
  updateHTML();
  updatePaper();
  time1 = millis();
  newData = 1;
}

void updatePaper() {
  //display.setTextSize(3);
  display.clearDisplay();
  display.setFont(&FreeSansBold18pt7b);
  display.setCursor(20, 40);
  display.print("Connect to ");
  display.print(ssid);
  display.println(" WiFi with pass: ");
  display.setCursor(240, 100);
  display.println(pass);
  display.setCursor(100, 150);
  display.print("Open Your web browser and open");
  display.setCursor(240, 210);
  display.print("http://");
  display.print(serverIP);
  display.println('/');
  display.println();
  display.fillRect(10, 240, 780, 4, BLACK);
  //display.println("User text");
  display.setCursor(xpos, ypos);
  display.print(txt);
  if (choice.toInt() != 0) display.drawBitmap(xPosPic, yPosPic, pic[choice.toInt() - 1], xSize[choice.toInt() - 1], ySize[choice.toInt() - 1], BLACK);
  display.drawBitmap(112, 547, image_data_footer, 572, 53, BLACK);
  display.display();
}
