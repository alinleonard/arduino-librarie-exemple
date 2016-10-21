/*
  I2C         Arduino
  ----------------
  GND          GND
  VCC          5V
  SDA          A4
  SCL          A5
  
  
  HCSR04      ARDUINO
  -------------------
  VCC         5v
  Trig        D12
  Echo        D11
  GND         GND
  
  Pentru mai multe informatii despre define: http://arduino.cc/en/Reference/Define
  Pentru mai multe informatii despre HCSR04: http://users.ece.utexas.edu/~valvano/Datasheets/HCSR04b.pdf
  
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define trigPin 12
#define echoPin 11

int avarageDistance[10]; 

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  lcd.init(); 
  lcd.backlight();
  lcd.print("Distanta:");
}

void loop() {
 
  long duration, distance;
  
  for(int i=0;i<10;i++){
    avarageDistance[i] = 0;
  }
  
  for(int y=0;y<10;y++){
    long duration, distance;
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    avarageDistance[y] = distance;
    delay(60);
  }
  
  int x = verify();
  if(x != 0){
    lcd.setCursor(0,1);
    for(int i= 0 ; i<16 ; i++){
      lcd.print(" ");
    }
    lcd.setCursor(0,1);
    lcd.print(x);
    lcd.print(" cm");
  }

}

int verify(){
   for(int i=0;i<10;i++){
    if(avarageDistance[i] >= 500){
      avarageDistance[i] = 0;
    }
    if(avarageDistance[i] <= 0.2){
      avarageDistance[i] = 0;
    }
    if(avarageDistance[i] != 0){
      return avarageDistance[i];
    }
  }
}