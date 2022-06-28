#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setLCD();
}

void loop() {
  Sensor.printLCD("powta");
}
