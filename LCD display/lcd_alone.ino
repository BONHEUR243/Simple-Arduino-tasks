#include<LiquidCrystal_I2C.h>
#include<Wire.h>


LiquidCrystal_I2C lcd(0x27 , 16, 2) ;

void setup() {
  //Wire.begin(A2,A3); 
  Wire.begin(); 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smart Greenlouse");
  lcd.setCursor(4,1);
  lcd.print("Based on IoT");
 /* lcd.setCursor(0,2);
  lcd.print("Made by @Arn & @Arm");
  lcd.setCursor(0,3);
  lcd.print("08-MAY-2024");*/

}

void loop() {
  // put your main code here, to run repeatedly:

}
