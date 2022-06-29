#include <WiFiClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

 
// Replace with your network credentials
const char* ssid = "Lab204";
const char* password = "ugv@12345";
const char* servers = "192.168.1.88";
 

WiFiClient clientOne;

 
String page = "";
int LEDPin = D6;
void setup(void){
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
   
  delay(1000);
  Serial.begin(9600);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
//  server.on("/", [](){
//    server.send(200, "text/html", page);
//  });
//  server.on("/LEDOn", [](){
//    server.send(200, "text/html", page);
//    digitalWrite(LEDPin, HIGH);
//    delay(1000);
//  });
//  server.on("/LEDOff", [](){
//    server.send(200, "text/html", page);
//    digitalWrite(LEDPin, LOW);
//    delay(1000); 
//  });
//  server.begin();
//  Serial.println("Web server started!");
}
 
void loop(void){
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http;  //Declare an object of class HTTPClient
 
    //http.begin("http://192.168.1.88:8090/data"); //Specify request destination
    http.begin(clientOne, servers, 5000, "/data");
 
    int httpCode = http.GET(); //Send the request
 
    if (httpCode > 0) { //Check the returning code
 
      String payload = http.getString();   //Get the request response payload
      Serial.println(payload);             //Print the response payload
     
      
      if(payload == "0")
        digitalWrite(LEDPin, HIGH);
      else
        digitalWrite(LEDPin, LOW);
 
    }else Serial.println("An error ocurred");
 
    http.end();   //Close connection
 
  }
 
  delay(2000);    //Send a request every 2 seconds
}
