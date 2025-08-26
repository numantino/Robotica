# Proyecto WIFI
Con este proyecto se pretende controlar el manejo de la wifi en sus diferentes modalidades

## Conexion a la misma wifi
Si nos queremos conectar a la misma wifi que tenemos en casa, tendremos que usarla en modo **WIFI_STA**.<br>

Esto es un ejemplo:
```c++
#include "wifiManager.hpp"

#define SSID "<Nombre de la red>"
#define PWD "<contraseña>"

WiFiManager wifi;

void setup() {
  //Inicializacion logs
  Serial.begin(115200);
  delay(1000);

  // Conectarse a WiFi
  wifi.initSTA(SSID, PWD);
}

void loop() {
  // Atender peticiones
  wifi.handleClient(<Mandar el HTML que se quiera>);
}
```

## Crear nuestra propia wifi
Si queremos crear nuestra propia wifi, para ello tendremos que usar el modo **WIFI_AP**.<br>

Esto es un ejemplo:
```c++
#include "wifiManager.hpp"

#define SSID "<Nombre de la red>"
#define PWD "<contraseña>" // Contraseña (mínimo 8 caracteres)

WiFiManager wifi;

void setup() {
  //Inicializacion logs
  Serial.begin(115200);
  delay(1000);

  // Conectarse a WiFi
  wifi.initAP(SSID, PWD);
}

void loop() {
  // Atender peticiones
  wifi.handleClient(<Mandar el HTML que se quiera>);
}
```
