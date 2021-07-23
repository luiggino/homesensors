#include "global.h"

unsigned long previousMillis = 0;
const long interval = 10000;

void setup() {
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("Init...");

  wifi.connect();
  mqtt.connect();
  

  Serial.println("Setup done");
}

void loop() {
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval && dht.read()) {
    previousMillis = currentMillis;

    float temperature = dht.getTemperature();  
    Serial.print("Temperature: ");
    Serial.println(temperature);
    mqtt.publish(mqtt_topic_dht_temperature, String(temperature).c_str());

    float humidity = dht.getHumidity();
    Serial.print("Humidity: ");
    Serial.println(humidity);
    mqtt.publish(mqtt_topic_dht_humidity, String(humidity).c_str());
  }

  gas.read();

  float lpg = gas.readLPG();
  Serial.print("LPG: ");
  Serial.println(lpg);
  
  float co = gas.readCO();
  Serial.print("CO: ");
  Serial.println(co);
  
  float smoke = gas.readSmoke();
  Serial.print("SMOKE: ");
  Serial.println(smoke);
  
  mqtt.loop();
}
