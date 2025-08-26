#pragma once
#include <ESP8266WiFi.h>

class WiFiManager {
private:
  WiFiServer server = WiFiServer(80);
public:
  /**
   * Conexion de wifi modo AP
   */
  void initAP(const char* ssid, const char* password) {
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    server.begin();
    Serial.print("AP iniciado. IP: ");
    Serial.println(WiFi.softAPIP());
  }

  /**
   * Conexion de wifi modo STA
   */
  void initSTA(const char* ssid, const char* password) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Conectando a WiFi: ");
    Serial.print(ssid);
    Serial.print("    ");
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nWiFi conectada");
    server.begin();
    Serial.print("IP local: ");
    Serial.println(WiFi.localIP());
  }

  /**
   * Funcion que apaga la wifi
   */
  void wifiOff() {
    Serial.println("Apagando WiFi...");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
  }
  
  /**
   * Envio de mensajes
   */
  void handleClient(String html) {
    WiFiClient client = server.available();
    if (client) {
      Serial.println("Cliente conectado");
      String request = "";
      unsigned long timeout = millis();

      while (client.connected() && millis() - timeout < 2000) {
        if (client.available()) {
          char c = client.read();
          request += c;

          // Si ya terminó la petición (línea vacía)
          if (request.endsWith("\r\n\r\n")) {
            Serial.println("Petición recibida:");
            Serial.println(request);

            // Responder con HTML
            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html; charset=utf-8");
            client.println("Connection: close");
            client.println();
            client.println(html);
            break;
          }
        }
      }
      delay(1);
      client.stop();
      Serial.println("Cliente desconectado");
    }
  }
};
