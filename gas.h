#ifndef GAS_H
#define GAS_H
#include <Arduino.h>

#include "MQ2.h"

class Gas {
  
  private:
    uint8_t m_pin;
    MQ2 mq2;
    
  public:
    Gas(uint8_t pin);   

    void read();
    float readLPG();
    float readCO();
    float readSmoke();
};
#endif //GAS_H
