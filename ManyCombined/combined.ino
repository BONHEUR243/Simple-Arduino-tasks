#define BLYNK_TEMPLATE_ID "TMPL2kyh9nNAW"
#define BLYNK_TEMPLATE_NAME "arno Arnold"
#define BLYNK_AUTH_TOKEN "SJSDKQeTeKW_cDrLDJdPBZthAby86JGh"

#include<LiquidCrystal.h>
#include<BlynkSimpleEsp32.h>
#include<WiFi.h>
//respectivement RS,EN,D4,D5,D6,D7
LiquidCrystal lcd(13,12,14,27,26,25);
long duration, distance;

#define TRIGGERPIN 16//D7
#define ECHOPIN 17//D8
const char* ssid = "t110183@ltr.liquidtelecom.com";
const char* password = "user1234";
const char* auth=BLYNK_AUTH_TOKEN;
 float potValue;
 int ldr;
 float ldrValue;
 int ldrPin=36;
 int potPin=34;
 int ledPin=21;
 int pot;
 int ldPin=22;
 BlynkTimer timer;

void myTimer() {
  Blynk.virtualWrite(V1,potValue);
  Blynk.virtualWrite(V2,ldrValue);
  Blynk.virtualWrite(V3,distance);
}
BLYNK_WRITE(V0){
  int value=param.asInt();
  if (value==1){
    digitalWrite(ldPin,HIGH);
  }
  else{
    digitalWrite(ldPin,LOW);
  }
}
BLYNK_CONNECTED(){
  Blynk.syncVirtual(V0);
}

void setup() {
  // put your setup code here, to run once:
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected");
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
    pinMode(ldPin,OUTPUT);
    
    Blynk.begin(auth,ssid,password);
    timer.setInterval(1000L,myTimer);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pot=analogRead(potPin);
  potValue=(100./4095.)*pot ;
  ldr= analogRead(ldrPin);
  ldrValue=(100./4095.)*ldr;


  
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
    lcd.print("Resistance:");
        lcd.setCursor(11,1);
        lcd.print(potValue);
        lcd.setCursor(18,1);
        lcd.print("k");
    lcd.setCursor(0,2);
    lcd.print("Distance :"); 
        lcd.setCursor(11,2);
        lcd.print(distance); 
        lcd.setCursor(15,2);
        lcd.print("cm"); 
    

    if (ldr<2000) {
      digitalWrite(ledPin,4095);
      lcd.setCursor(6,3);
      lcd.print("LED IS ON");
    }
    else {
      digitalWrite(ledPin,0);
      lcd.setCursor(6,3);
      lcd.print("LED IS OFF");
    }
    
    Blynk.run();
    timer.run();
}
