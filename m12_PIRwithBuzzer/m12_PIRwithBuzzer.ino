/*
Senzorul pir trebuie alimentat la 5v 
VCC - > 5V (Arduino)
OUT - > 2 (Arduino pin digital)
GND -> GND

Buzzer | Arduino
VCC -> 5v
GND -> GND
I/O -> 3D (pinul 3 digital)

HIGH = 1
LOW = 0

In acest exemplu difinim o functie playTone
*/

int inputPin = 2;
int pirState = LOW;
int val = 0;
int inputBuzzer = 3;
long prevTime = 0;


void setup(){
  pinMode(inputPin, INPUT);
  pinMode(inputBuzzer,OUTPUT);
  Serial.begin(9600);
  Serial.println("Wait 5 sec for the PIR to initialize");
}
void loop(){
 val = digitalRead(inputPin);

 if(val == HIGH){
   playTone(1);
   delay(150);
   if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
   }
 } else{
     playTone(0);
     delay(300);
     if(pirState == HIGH ){
       Serial.println("Motion ended!");
       pirState = LOW;
     }
   }
}

void playTone(int mode){
  unsigned long time = millis();
 if(mode == 1){
   if(time-prevTime > 200){
     digitalWrite(inputBuzzer,HIGH);
     prevTime = time;
   }
   else{
     digitalWrite(inputBuzzer,LOW);
   }
 }else{
   digitalWrite(inputBuzzer,LOW);
 }
}
  
