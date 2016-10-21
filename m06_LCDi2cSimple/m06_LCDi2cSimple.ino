/*
  I2C         Arduino
  ----------------
  GND          GND
  VCC          5V
  SDA          A4
  SCL          A5
  
  Dupa ce conectati toate firele pentru a putea determina adresa I2C folositi exemplul Scanare Adresa I2C.
  
  Mai multe informatii : Librarile Wire : http://arduino.cc/en/reference/wire
*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Definim Adresa , numarul de coloane , numarul de linii de pe LCD ( exemplul folosit are adresa : 0x27 , si este un LCD 16x2
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  //Folosim functia init() pentru a initializa LCD-ul (functia init() este extrasa din librarile LiquidCrystal_I2C.h )
  lcd.init();                      
  lcd.backlight();
  /*Ca si cu serialul folosim print pentru a afisa pe LCD un sir de caractere */
  lcd.print("Melectronice.ro");
}

void loop()
{
  
}