#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
BLEScan* pBLEScan;
const int WINDOW_SIZE = 8;
int rssiBuffer[WINDOW_SIZE];
int indexBuffer = 0;
bool bufferFilled = false;
String productName = "Dairy Product";
String floorName = "Ground Floor";

String lockedZone = "Unknown";
int stableCounter = 0;
int calculateAverage()
{
  int sum = 0;
  int count = bufferFilled ? WINDOW_SIZE : indexBuffer;
  if(count == 0)
  return -100;
  for(int i=0;i<count;i++)
  sum += rssiBuffer[i];
  return sum / count;
}
String detectZone(int rssi)
{
  if(rssi >= -39)
  return "Zone A (Near)";
  else if(rssi >= -55)
  return "Zone B (Mid)";
  else
  return "Zone C (Far)";
}
