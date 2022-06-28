#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setRelay(D6);
}

void loop() {
  Sensor.driveRelay(D6);
}
