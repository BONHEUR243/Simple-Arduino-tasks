#define TRIGGERPIN 13//D7
#define ECHOPIN 15//D8

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(TRIGGERPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

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
  //Serial.println(potValue);
  delay(200);

}
