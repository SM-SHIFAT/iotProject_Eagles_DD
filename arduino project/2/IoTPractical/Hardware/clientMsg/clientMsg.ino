#include <esp8266.h>

const char* ssid = "ABRAR2";
const char* password = "abrar96009";
const char* server = "192.168.43.2";

esp8266Class esp;

void setup() {
  Serial.begin(9600);
  esp.wifiBegin();
  esp.wifiConnect(server, ssid, password);
}

void loop() {
  esp.data = 1971;
  esp.wifiSend(esp.data);
}
