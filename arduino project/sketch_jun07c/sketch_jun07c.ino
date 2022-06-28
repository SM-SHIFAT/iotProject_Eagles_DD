#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "DHT.h"

DHT dht;


const char* ssid = "my";
const char* password = "12345679";

int httpResponseCode = 0;
WiFiClient clientOne;
HTTPClient http;

void setup(void)
{
  Serial.begin(115200);
  //Serial.begin(9600);
  WiFi.begin(ssid, password);

  //wait until wifi connects
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  
  }


  Serial.println("");                     // newline
  Serial.println("WiFi connected");       // debug message
  Serial.println(WiFi.localIP());

  int httpStatus = http.begin(clientOne, "192.168.0.96", 5000, "/upload");
  Serial.println("HTTP REQ STATUS: " + String(httpStatus));
  http.addHeader("Content-Type", "text/plain");

  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

  dht.setup(D6);   /* set pin for data communication */

}

void loop() {

  delay(dht.getMinimumSamplingPeriod());  /* Delay of amount equal to sampling period */  

  float humidity = dht.getHumidity();     /* Get humidity value */
  float temperature = dht.getTemperature(); /* Get temperature value */
  char str[30],str2[30];
  sprintf(str, "%f ", humidity);
  sprintf(str2, "%f", temperature);
  strcat(str,str2);
  Serial.println(str);
    httpResponseCode = http.POST(str);

    Serial.println(httpResponseCode);
    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println(payload);

    } else Serial.println("Error ocurred");
  
}
