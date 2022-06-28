#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setDHT(D6);
}

void loop() {
  Sensor.readDHT();
  Sensor.printDHT();
}
