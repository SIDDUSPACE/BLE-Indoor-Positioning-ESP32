#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEBeacon.h>
#include <BLEAdvertising.h>
BLEAdvertising *pAdvertising;
void setup()
{
  Serial.begin(115200);
  BLEDevice::init("BLE_ZONE_BEACON");
  BLEBeacon beacon = BLEBeacon();
  beacon.setManufacturerId(0x4C00);
  beacon.setMajor(1);
  beacon.setMinor(1);
  beacon.setSignalPower(-59);
  beacon.setProximityUUID(BLEUUID("12345678-1234-1234-1234-1234567890AB"));
  BLEAdvertisementData advertisementData;
  advertisementData.setFlags(0x04);
  std::string beaconPayload = "";
  beaconPayload += (char)0x02;
  beaconPayload += (char)0x15;
  beaconPayload += beacon.getData();
  advertisementData.addData(beaconPayload);
  pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->setAdvertisementData(advertisementData);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinInterval(0x20);
  pAdvertising->setMaxInterval(0x40);

  BLEDevice::startAdvertising();
  Serial.println("BLE Beacon Transmitter Started");
}
void loop()
{
 
}
