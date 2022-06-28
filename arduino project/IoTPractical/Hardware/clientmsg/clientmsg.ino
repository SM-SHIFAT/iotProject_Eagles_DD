#include <esp8266.h>

const char* server = "192.168.43.20";

esp8266Class esp;

void setup() {
  Serial.begin(9600);
  esp.wifiBegin();
  esp.wifiConnect(server);
}

void loop() {
  esp.data = 1971;
  //esp.data = esp.readRFID();
  //esp.data = analogRead(A0);
  esp.wifiSend(esp.data);
}
