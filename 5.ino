#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

DHT dht;

float humid;
float temp;
String t="T=", c=" C", h=" H=",p=" %"; 

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

String result;
String messageToScroll = "This is a scrolling message with more than 16 characters";


void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

void setup(){
  Serial.begin(9600);
  lcd.begin(); 
  lcd.backlight();                    

  dht.setup(D6);
}

void loop(){
  // print scrolling message
  scrollText(0, messageToScroll, 250, lcdColumns);

  delay(dht.getMinimumSamplingPeriod());
  humid = dht.getHumidity();
  temp = dht.getTemperature();

  result = t + String(temp) + c + h + String(humid) + p;

  lcd.setCursor(0, 1);
  lcd.print(result);
  
 
}
