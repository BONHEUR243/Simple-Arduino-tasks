#include<LiquidCrystal.h>

//respectivement RS,EN,D4,D5,D6,D7
LiquidCrystal lcd(13,12,14,27,26,25);

#define TRIGGERPIN 13//D7 //nodemcu
#define ECHOPIN 15//D8

 int potValue;
 int ldrValue;
 int ldrPin=36;
 int potPin=34;
 int ledPin=22;

void setup() {
  // put your setup code here, to run once:
    lcd.begin(20,4);
    //lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Smart greenhouse"); 
    lcd.setCursor(0,1);
    lcd.print("Made by CITO"); 
    lcd.setCursor(0,2);
    lcd.print("Powered by Ciku"); 
    lcd.setCursor(0,3);
    lcd.print("LE 07-MAI-2024"); 
    delay(6000);

    Serial.begin(115200);
    pinMode(TRIGGERPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
    pinMode(potPin,INPUT);
    pinMode(ldrPin,INPUT);
    pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue= analogRead(potPin);
  ldrValue= analogRead(ldrPin);

  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  Serial.println("");
  Serial.println(potValue);
  delay(200);

  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ldr Value:");
        lcd.setCursor(12,0);
        lcd.print(ldrValue);
    lcd.setCursor(0,1);
    lcd.print("Potentiometer:");
        lcd.setCursor(14,1);
        lcd.print(potValue);
    lcd.setCursor(0,2);
    lcd.print("Distance :"); 
        lcd.setCursor(12,2);
        lcd.print(distance); 
        lcd.setCursor(17,2);
        lcd.print("cm"); 
    

    if (ldrValue<2000) {
      digitalWrite(ledPin,4095);
      lcd.setCursor(6,3);
      lcd.print("LED IS ON");
    }
    else {
      digitalWrite(ledPin,0);
      lcd.setCursor(6,3);
      lcd.print("LED IS OFF");
    }

}
