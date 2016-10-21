/*
  I2C         Arduino
  ----------------
  GND          GND
  VCC          5V
  SDA          A4
  SCL          A5

    DAT (SDA) to I2C Data (on the Uno, this is A4 on the Mega it is 20 and on the Leonardo digital 2)
    CLK (SCL) to I2C Clock (on the Uno, this is A5 on the Mega it is 21 and on the Leonardo digital 3)

*/
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

char Name[15] = {'M','e','l','e','c','t','r','o','n','i','c','e','.','r','o'};

void setup()
{
  lcd.init();                     
  lcd.backlight();
  lcd.print("Melectronice.ro");
}

void loop()
{ 
  /* Setam cursorul , linia pe care sa scrie ( prima variabile este randul si a doua coloana */
  lcd.setCursor(0,1);
  /* Folosim o functie de tip for() pentru a da un efect de scriere (caracter cu caracter) pe LCD 
    Pentru mai multe informatii: http://arduino.cc/en/Reference/for 
  */
  for(int i=0;i<15;i++){
    lcd.print(Name[i]);
    delay(500);
    if(i==14){
      lcd.clear();
      lcd.noBacklight();
      delay(2000);
      lcd.setCursor(0,0);
      lcd.print("Va multumim!");
      lcd.backlight();
      delay(1000);
    }
  }
}