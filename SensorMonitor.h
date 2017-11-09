/*
 * Sensor Monitor
 * ensc 100 2017
 *
 * used to help monitor 2 DHT22 sensors and provide some functionality
 */
// #ifdef SENSMON_H
// #define SENSMON_H

#include "dht.h"

class SensorMonitor {
  public:
    SensorMonitor() : mTemp(0.f), mHum(0), mPin1(7), mPin2(8) {}
    SensorMonitor(const int& pin1, const int& pin2) : 
      mPin1(pin1),
      mPin2(pin2)
    {}

    void setTemp(const float& temp);
    void setHum(const float& hum);

    // read temp and hum into the references
    int readValues(float& temp1, float& hum1, float& temp2, float& hum2);

  private:
    float mTemp;
    float mHum;
    
    // DHT object
    dht mDHT1;
    dht mDHT2;
    
    // Arduino Pin
    byte mPin1;
    byte mPin2;
};

// #endif  SENSMON_H 