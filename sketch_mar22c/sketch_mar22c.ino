#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;
void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String input = Serial.readStringUntil('\n');
    if(input == "yes"){
      rotateServo360();
    }
  }
  delay(20);
}

void rotateServo360(){
  for(int angle = 0; angle <= 180; angle++){
    myServo.write(angle);
    delay(15);
  }
  delay(1000); // Wait for 1 second at 180 degrees
  for(int angle = 180; angle >= 0; angle--){
    myServo.write(angle);
    delay(15);
  }
}
