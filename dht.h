#ifndef DHT_H
#define DHT_H
#include <Arduino.h>

#include "DHTLib.h"

class Dth {
  
  private:
    DHTLib dht;
    uint8_t m_pin;
    float humidity;
    float temperature;
    
  public:
    Dth(uint8_t pin);   
   
    boolean read();

    float    getHumidity() { return humidity; };
    float    getTemperature() { return temperature; };
};
#endif //DHT_H
