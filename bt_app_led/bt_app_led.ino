#include<BluetoothSerial.h>

BluetoothSerial serialBT;
const int ledPin = 2;

void setup() {
  // put your setup code here, to run once:
  serialBT.begin("ESP32 Bluetooth");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (serialBT.available()) {
    char c = serialBT.read();
    if(c=='1'){
      digitalWrite(ledPin,HIGH);
    } else if(c=='0'){
      digitalWrite(ledPin,LOW);
    }
  }
}
