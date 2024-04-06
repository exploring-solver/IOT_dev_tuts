#include<BluetoothSerial.h>

BluetoothSerial serialBT;
char cmd = '0'; // Initialize cmd to a default value

void setup() {
  // put your setup code here, to run once:
  serialBT.begin("ESP32-BT");
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (serialBT.available()) {
    cmd = serialBT.read();
    delay(10); // Delay for stability
  }

  // Use these commands to control the LED connected to pin 2
  if (cmd == '1') {
    digitalWrite(2, HIGH); // Turn LED on
  }
  else if (cmd == '0') {
    digitalWrite(2, LOW); // Turn LED off
  }
}
