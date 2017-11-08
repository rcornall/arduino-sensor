/*
 * SensorMonitor Implementation
 * ensc 100 2017
 */
#include "SensorMonitor.h"

void SensorMonitor::setTemp(const float& temp) {
  mTemp = temp;
}


void SensorMonitor::setHum(const float& hum) {
  mHum = hum;
}

int SensorMonitor::readValues(float& temp, float& hum) {

  int dhtStatus = mDHT.read22(mPin);
  int ret;
  switch (dhtStatus)
  {
    case DHTLIB_OK:  
      Serial.print("READ OK,\t"); 
      ret = 0;
      break;
    case DHTLIB_ERROR_CHECKSUM: 
      Serial.print("Checksum error,\t"); 
      ret = -1;
      break;
    case DHTLIB_ERROR_TIMEOUT: 
      Serial.print("Time out error,\t"); 
      ret = -2;
      break;
    default: 
      Serial.print("Unknown error,\t"); 
      ret = -3;
      break;
  }

  if (ret==0)
  {
    temp = mDHT.temperature;
    hum = mDHT.humidity;
  }
  return ret;
}