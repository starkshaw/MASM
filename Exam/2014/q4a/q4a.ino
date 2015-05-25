int sensorValue;
int wiperPosition;

// LED pin settings
int redLED = 3;
int amberLED = 4;
int greenLED = 5;

void setup() {
 Serial.begin(9600);
 pinMode(redLED, OUTPUT);
 pinMode(amberLED, OUTPUT);
 pinMode(greenLED, OUTPUT);
}

void loop() {
 sensorValue = analogRead(A0);
 wiperPosition = map(sensorValue, 0, 1023, 0, 270);
 Serial.println(sensorValue);
 delay(10);
 if(wiperPosition > 0 && wiperPosition <= 100) {
   digitalWrite(redLED, LOW);
   digitalWrite(amberLED, LOW);
   digitalWrite(greenLED, HIGH);
 } else if(wiperPosition > 100 && wiperPosition <= 200) {
   digitalWrite(redLED, LOW);
   digitalWrite(amberLED, HIGH);
   digitalWrite(greenLED, LOW);
 } else {
   digitalWrite(redLED, HIGH);
   digitalWrite(amberLED, LOW);
   digitalWrite(greenLED, LOW);
 }
}


