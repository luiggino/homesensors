 #include "mqtt.h"

 Mqtt::Mqtt(String broker, int port) {
  this->broker = broker;
  this->port = port;
 }

void Mqtt::connect() {
  //connecting to a mqtt broker
  client.setClient(espClient);
  client.setServer(broker.c_str(), port);
  //client.setCallback(callback);

}

 void Mqtt::reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish(publish_reset, "reset");
      // ... and resubscribe
      //client.subscribe("dofIn");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void Mqtt::publish(String topic, String message) {
  Serial.println(topic);
  client.publish(topic.c_str(), message.c_str());
}

 void Mqtt::loop() {  
  if (!client.connected()) {
    reconnect();
  }


  client.loop();
 }
