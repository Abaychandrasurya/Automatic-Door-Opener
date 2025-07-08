#include <Servo.h>

Servo doorServo;

const int pirPin = 2;
const int servoPin = 9;
const int redLEDPin = 4;
const int greenLEDPin = 5;
const int buzzerPin = 6;

bool doorOpen = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  doorServo.attach(servoPin);
  doorServo.write(0);
  digitalWrite(redLEDPin, HIGH);
  digitalWrite(greenLEDPin, LOW);

  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH && !doorOpen) {
    Serial.println("Motion detected!");
    
    doorServo.write(90);
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(buzzerPin, LOW);

    doorOpen = true;
    delay(5000); 
    
    doorServo.write(0);
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    doorOpen = false;
  }

  delay(100);
}
