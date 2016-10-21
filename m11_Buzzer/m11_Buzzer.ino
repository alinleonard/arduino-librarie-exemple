/*
Buzzer     Arduino
------------------
VCC       5v
GND       GND
I/O       3D (pinul 3 digital)
*/
int inputBuzzer = 3;

void setup(){
  pinMode(inputBuzzer,OUTPUT);
}
void loop(){
  digitalWrite(inputBuzzer,HIGH);
  delay(1000);
  digitalWrite(inputBuzzer,LOW);
  delay(1000);
}