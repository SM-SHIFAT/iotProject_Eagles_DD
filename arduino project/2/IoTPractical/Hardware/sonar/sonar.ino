#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setSonar(D5,D6);
}

void loop() {
  Sensor.readSonar(D5,D6);
  Sensor.printSonar();
}
