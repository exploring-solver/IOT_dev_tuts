#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;
int txValue = 0;

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID_TX "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    deviceConnected = true;
  }
  void onDisconnect(BLEServer *pServer) {
    deviceConnected = false;
  }
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  BLEDevice::init("ESP32");

  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(BLEUUID(SERVICE_UUID));

  pCharacteristic = pService->createCharacteristic(
    BLEUUID(CHARACTERISTIC_UUID_TX),
    BLECharacteristic::PROPERTY_NOTIFY);

  pCharacteristic->addDescriptor(new BLE2902());

  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Waiting for a client connection to notify...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (deviceConnected) {
    txValue = random(-10, 20);

    char txString[8];
    dtostrf(txValue, 1, 2, txString);

    pCharacteristic->setValue((uint8_t*)txString, strlen(txString));
    pCharacteristic->notify();

    Serial.println("Sent value: " + String(txString));
    delay(500);
  }
}
