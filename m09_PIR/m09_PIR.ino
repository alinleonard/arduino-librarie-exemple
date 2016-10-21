/*
Senzorul pir trebuie alimentat la 5v 
VCC - > 5V (Arduino)
OUT - > 2 (Arduino pin digital)
GND -> GND
HIGH = 1
LOW = 0
*/

int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup(){
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
  Serial.println("Wait 5 sec for the PIR to initialize");
}
void loop(){
 val = digitalRead(inputPin);

 if(val == HIGH){
   delay(150);
   if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
   }
 }
 else{
     delay(300);
     if(pirState == HIGH ){
       Serial.println("Motion ended!");
       pirState = LOW;
     }
   }
   
}
