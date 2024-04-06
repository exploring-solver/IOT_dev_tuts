#include <ESP32Servo.h>
Servo Myservo;
#define trigPin 27
#define echoPin 12
#define MLa 32
#define MLb 33
#define MRa 26
#define MRb 23
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Myservo.attach(14);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  Serial.println(distance);
  
  if (distance > 15) {
    Myservo.write(90);
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);
    digitalWrite(MLa, LOW);
  } else if (distance < 10 && distance > 0) {
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);
    delay(100);
    
    Myservo.write(0);
    delay(500);
    Myservo.write(180);
    delay(500);
    Myservo.write(90);
    delay(500);
    
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, HIGH);
    delay(500);
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);  
    delay(100);  
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);  
    delay(500);
  }
}
