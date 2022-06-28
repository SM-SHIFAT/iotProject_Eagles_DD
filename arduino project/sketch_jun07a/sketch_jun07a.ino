#include <rdm6300.h>

Rdm6300 rdm6300;
int32_t cardID = 0;

void setup()
{
  Serial.begin(9600);
  rdm6300.begin(D6);
}

void loop()
{
  if (rdm6300.is_listening())
    cardID = rdm6300.get_tag_id();
    Serial.println(cardID);
    delay(2000);
}
