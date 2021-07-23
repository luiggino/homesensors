#ifndef WIFI_H
#define WIFI_H
#include <Arduino.h>
#include <ESP8266WiFi.h>

class Wifi {
  
  private:
    String m_ssid;
    String m_password;
    
  public:
    Wifi(const String ssid, const String password);
    void connect();
    
   
    String getIp();
};
#endif //WIFI
