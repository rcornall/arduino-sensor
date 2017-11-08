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
    SensorMonitor() : mTemp(0.f), mHum(0), mPin(7) {}
    SensorMonitor(const int& pin) : mPin(pin) {
      Serial.print("DHT pin: ");
      Serial.print(mPin);
      Serial.print("\n");
    }

    void setTemp(const float& temp);
    void setHum(const float& hum);

    // read temp and hum into the references
    int readValues(float& temp, float& hum);

  private:
    float mTemp;
    float mHum;
    
    // DHT object
    dht mDHT;
    
    // Arduino Pin
    byte mPin;
};

// #endif  SENSMON_H 