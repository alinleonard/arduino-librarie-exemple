/*
  I2C         Arduino
  ----------------
  GND          GND
  VCC          5V
  SDA          A4
  SCL          A5
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

/*Definim o variabile de tip String pentru a stoca datele primite pe serial
Pentru mai multe informatii despre String : http://arduino.cc/en/Reference/string */
String content = "";
char character;


void setup()
{
  Serial.begin(9600);
  lcd.init();                    
  lcd.backlight();
  lcd.print("Melectronice.ro");
  lcd.setCursor(0,1);
}

void loop()
{
  /* Folosim o functie de tip while (cat timp) pentru a prinde toate datele din buffer */
  while(Serial.available()){
    character = Serial.read();
    /*Folosim functia implicita concat() pentru a strange toate datele de pe serial intr-un singur String
      Mai multe informatii despre concat() http://arduino.cc/en/Reference/StringConcat 
    */
    content.concat(character); 
    delay (10);
  }
  if(content != ""){
    lcd.print(content);
    if(content.length() > 15)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      for(int i =0; i<content.length(); i++){
        if(i <= 16){
          lcd.print(content.charAt(i));
          delay(50);
          if(i == 16)
            lcd.setCursor(0,1);
        }
        if(i > 15){
          lcd.print(content.charAt(i));
          delay(50);
        }
        
      }
    }
    if(content == "clear"){
      lcd.clear();
      lcd.setCursor(0,0);
    }
    content = "";
  }
}

/*
  Se pot face foarte multe modificari la acest exemplu si ne putem juca pentru a adauga mai multe comenzi 
  si mai multe functii 
*/