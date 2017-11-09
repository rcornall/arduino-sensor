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

int SensorMonitor::readValues(float& temp1, float& hum1, float& temp2, float& hum2) {

  int dhtStatus1 = mDHT1.read22(mPin1);
  int dhtStatus2 = mDHT2.read22(mPin2);
  int ret;
  if(dhtStatus1 == DHTLIB_OK) {
    Serial.print("READ SENSOR 1 OK,\n"); 
    ret = 0;
  } else {
    ret = 1;
  }
  if(dhtStatus2 == DHTLIB_OK) {
    Serial.print("READ SENSOR 2 OK,\n"); 
    ret = 0;
  } else {
    ret = 1;
  }
  if (ret==0)
  {
    temp1 = mDHT1.temperature;
    hum1 = mDHT1.humidity;
    temp2 = mDHT2.temperature;
    hum2 = mDHT2.humidity;    
  }
  return ret;
}