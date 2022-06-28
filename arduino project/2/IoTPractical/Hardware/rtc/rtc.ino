#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setRTC();
}

void loop() {
  Sensor.printRTC();
}
