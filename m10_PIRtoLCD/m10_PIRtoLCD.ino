/*
LCD

  I2C         Arduino
  ----------------
  GND          GND
  VCC          5V
  SDA          A4
  SCL          A5

PIR

  PIR         Arduino
  ----------------
  VCC         5V
  OUT         D2
  GND         GND

Semnificatie:
HIGH = 1
LOW = 0

FUNCTII LCD POSIBILE
-----------------------------
  init	KEYWORD2
  begin	KEYWORD2
  clear	KEYWORD2
  home	KEYWORD2
  noDisplay	KEYWORD2
  display	KEYWORD2
  noBlink	KEYWORD2
  blink	KEYWORD2
  noCursor	KEYWORD2
  cursor	KEYWORD2
  scrollDisplayLeft	KEYWORD2
  scrollDisplayRight	KEYWORD2
  leftToRight	KEYWORD2
  rightToLeft	KEYWORD2
  shiftIncrement	KEYWORD2
  shiftDecrement	KEYWORD2
  noBacklight	KEYWORD2
  backlight	KEYWORD2
  autoscroll	KEYWORD2
  noAutoscroll	KEYWORD2
  createChar	KEYWORD2
  setCursor	KEYWORD2
  print	KEYWORD2
  blink_on	KEYWORD2
  blink_off	KEYWORD2
  cursor_on	KEYWORD2
  cursor_off	KEYWORD2
  setBacklight	KEYWORD2
  load_custom_character	KEYWORD2
  printstr	KEYWORD2
-----------------------------
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup(){
  pinMode(inputPin, INPUT);
  lcd.init();  
  lcd.backlight();
  Serial.begin(9600);
  Serial.println("Wait 5 sec for the PIR to initialize");
  lcd.print("Alarm enabled");
  lcd.setCursor(0,1);
}

void loop(){
 val = digitalRead(inputPin);

 if(val == HIGH){
   delay(150);
   if (pirState == LOW) {
      lcd.print("Motion Detected!");
      pirState = HIGH;
   }
 } else{
     delay(300);
     if(pirState == HIGH ){
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Alarm enabled");
       lcd.setCursor(0,1);
       lcd.print("Motion Ended!");
       pirState = LOW;
     }
   }
}
