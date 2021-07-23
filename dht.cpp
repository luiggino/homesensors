#include "dht.h"
#include "DHTLib.h"

#define DHTTYPE DHT11

Dth::Dth(uint8_t pin) :
  humidity(0.0),
  temperature(0.0),
  m_pin(pin) 
{
  dht.begin(m_pin, DHTTYPE);
}
   
boolean Dth::read() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return false;
  }

  humidity = h;
  temperature = t;

  return true;
}
