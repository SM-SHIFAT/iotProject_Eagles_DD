int variable =0;
void setup(){
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop(){
  variable =analogRead(A0);
  Serial.println(variable);
}
