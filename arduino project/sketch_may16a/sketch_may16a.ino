int trigPin = 3;
int ecoPin = 2 ;
int revleft4 = 4;
int fwdleft5 = 5;

int revright6 = 6; 
int fwdright7 = 7;
int ena = 9;
int enb = 10;
long duration, distance;


void setup(){
  Serial.begin(9600);
  pinMode(revleft4,OUTPUT); 
  pinMode(fwdleft5,OUTPUT); 
  pinMode(revright6,OUTPUT); 
  pinMode(fwdright7,OUTPUT);
  pinMode (trigPin,OUTPUT);
  pinMode(ecoPin,INPUT);
  pinMode (ena, OUTPUT);
  pinMode (enb, OUTPUT);
  
}

void loop() {
     digitalWrite(trigPin,LOW);  
     delayMicroseconds(2);   
     digitalWrite(trigPin,HIGH);  
     delayMicroseconds(10);
     duration = pulseIn(ecoPin, HIGH);
     distance = duration * 0.034 / 2 ;
     Serial.println(distance);
     delay (10);
     if (distance > 10);
     {
       digitalWrite(fwdright7,HIGH);
       digitalWrite(revright6,LOW);
       digitalWrite(fwdleft5,HIGH);
       digitalWrite(revleft4,LOW);
       analogWrite(ena,80);
       analogWrite(enb,80);
       
     }
     if (distance<10);
     {
       digitalWrite(fwdright7,LOW);
       digitalWrite(revright6,HIGH);
       digitalWrite(fwdleft5,LOW);
       digitalWrite(revleft4,HIGH);
       analogWrite(ena,80);
       analogWrite(enb,80);
       delay (1000);

       digitalWrite(fwdright7,HIGH);
       digitalWrite(revright6,LOW);
       digitalWrite(fwdleft5,LOW);
       digitalWrite(revleft4,LOW);
       analogWrite(ena,80);
       analogWrite(enb,80);
       delay (500);
     }
     }
}



void backward() 
{
     digitalWrite(IN1,LOW);   
     digitalWrite(IN2,HIGH);  
     digitalWrite(IN3,LOW);   
     digitalWrite(IN4,HIGH);  
}


void quick_left()
{
     digitalWrite(IN1,LOW); 
     digitalWrite(IN2,HIGH);
     digitalWrite(IN3,HIGH);  
     digitalWrite(IN4,LOW);
}


void quick_right() 
{
     digitalWrite(IN1,HIGH);    
     digitalWrite(IN2,LOW);     
     digitalWrite(IN3,LOW);   
     digitalWrite(IN4,HIGH);   
}
  void Stop()
{
  digitalWrite(IN1,LOW);    
     digitalWrite(IN2,LOW);
     digitalWrite(IN3,LOW);   
     digitalWrite(IN4,LOW);
}

void loop()
{
  
  if (Serial.available()>0) 
  {
    delay(3);
    char NewData = Serial.read();
    
    Serial.println(NewData);
        
    if(NewData == 'F')
     {
       
       forward(); //ROBOT Move to Forward Direction . 
     }
     
     else if(NewData == 'B')
     {
       
       backward(); //ROBOT Move to Backward Direction . 
     }
     
     else if(NewData == 'L')
     {
       
       quick_left(); //ROBOT Fast Move to Left turn.    
     }
     
     else if(NewData == 'R')
     {
      
       quick_right(); //ROBOT Fast Move to Right turn.  
     }
     
     else if(NewData == 'S')
     {

      Stop();
       
     }
  }}
