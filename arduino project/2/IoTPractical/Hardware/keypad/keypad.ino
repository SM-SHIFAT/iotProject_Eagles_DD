#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = Sensor.readKeys();
  Sensor.printKeys(key);
}
