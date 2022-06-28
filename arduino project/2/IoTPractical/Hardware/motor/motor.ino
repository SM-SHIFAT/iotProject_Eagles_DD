#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setMotor(D7, D8, D6);
}

void loop() {
  Sensor.runMotor(D6, 120);
}
