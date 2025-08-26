#include "webServerManager.hpp"

WebServerManager web;

#define SSID "Numantino"
#define PWD  "1234567890"

void setup() {
  Serial.begin(115200);
  delay(1000);

  web.initSTA(SSID, PWD);
}

void loop() {
  WiFiClient client = web.getClient();
  if (client) {
    Serial.println("Cliente conectado");

    String request = web.readRequest(client);
    Serial.println("Petición:");
    Serial.println(request);

    String valor = web.getParam(request, "valor");

    if (valor != "") {
      web.showPage(client,
        "<h1>Has enviado el valor: " + valor + "</h1>");
    } else {
      web.showPage(client,
        "<form action='/set'>"
        "Introduce un número: <input type='number' name='valor'><br><br>"
        "<input type='submit' value='Enviar'>"
        "</form>");
    }

    client.stop();
    Serial.println("Cliente desconectado");
  }
}
