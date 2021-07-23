#include "wifi.h"

 Wifi::Wifi(const String ssid, const String password) 
 : m_ssid(ssid),
   m_password(password)
 {
 }
 
void Wifi::connect() {
  //m_buzzer.sound();
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);

  WiFi.disconnect();
  
  WiFi.begin(m_ssid, m_password);
  Serial.println();
  Serial.print("Connecting to "); 
  Serial.print(m_ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
}

String Wifi::getIp() {
  return WiFi.localIP().toString();
}
