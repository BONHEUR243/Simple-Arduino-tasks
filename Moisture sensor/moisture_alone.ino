//moisture trial alone 


int moistureSensorPin = A0;
int moistureSensorValue; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(moistureSensorPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  moistureSensorValue = analogRead(moistureSensorPin);
  Serial.println (moistureSensorValue);
}
