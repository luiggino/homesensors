#include "wifi.h"
#include "mqtt.h"
#include "dht.h"
#include "gas.h"

// DHT config.
#define DHT_PIN D5
Dth dht(DHT_PIN);

// Gas config
#define GAS_PIN A0
Gas gas(GAS_PIN);

// WIFI
const char* ssid = "";
const char* password = "";
Wifi wifi(ssid, password);

//MQTT
const char *mqtt_broker = "192.168.1.82";
const int mqtt_port = 1883;
const char *mqtt_topic_dht_temperature = "/dht/temperature";
const char *mqtt_topic_dht_humidity = "/dht/humidity";
Mqtt mqtt(mqtt_broker, mqtt_port);
