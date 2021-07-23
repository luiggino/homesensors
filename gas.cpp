#include "gas.h"

Gas::Gas(uint8_t pin) :
  m_pin(pin) {
  mq2.setPin(m_pin);

  mq2.begin();
}

void Gas::read() {
  mq2.read(true);
}

float Gas::readLPG() {
 return mq2.readLPG(); 
}

float Gas::readCO() {
  return mq2.readCO();
}

float Gas::readSmoke() {
  return mq2.readSmoke();
}
