#include <iotSensor.h>

sensorClass Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.setRFID(D6);
}

void loop() {
  int card = Sensor.readCard();
  Sensor.printCard(card);
}
