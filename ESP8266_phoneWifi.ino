#include "ESP8266WiFi.h"
void setup() {


}

void loop() {
  print(WiFi.STATION.getip());
  WiFi.setmode(WiFi.STATION);
  WiFi.STATION.config("HTC E9+","1234567890");
  print(WiFi.STATION.getip());
}
