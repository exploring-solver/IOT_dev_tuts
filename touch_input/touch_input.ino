int ledPin = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(touchRead(T0) <30){
    digitalWrite(ledPin , HIGH);
  } else {
    digitalWrite(ledPin , LOW);
  }
  delay(200);
}
