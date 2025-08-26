#include "wifiManager.hpp"

#define SSID "Numantino"
#define PWD "1234567890"

WiFiManager wifi;

void setup() {
  //Inicializacion logs
  Serial.begin(115200);
  delay(1000);

  // Conectarse a WiFi
  wifi.initSTA(SSID, PWD);
}

void loop() {
  // Página de prueba
  String html = "<!DOCTYPE html><html><head><title>NodeMCU</title></head><body><h1>Hello desde NodeMCU!</h1></body></html>";
  // Atender peticiones
  wifi.handleClient(html);
}
