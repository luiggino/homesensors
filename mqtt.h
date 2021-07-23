#ifndef MQTT_H
#define MQTT_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
class Mqtt {
  
  private:
    WiFiClient espClient;
    PubSubClient client;
    String broker;
    int port;
    
  public:
    Mqtt(String broker, int port);
    void connect();
    void reconnect();

    void publish(String topic, String message);
    
   
    void loop();
};
#endif //MQTT_H
