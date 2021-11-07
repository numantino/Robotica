#include "util/sensores/sensorDHT22.hpp"
#include "util/clienteIFTTT.hpp"
#include "datos.h"

void setup()
{
    Serial.begin(115200);
    delay(10);
    //Inicializacion del componente, dependiendo de la clase incluida con anterioridad
    //Incluir datos del SSID donde nos queramos conectar
    inicializacion(SSID_CASA, PWD_CASA);
}
void loop()
{
  //Lectura sensor DHT22
  TempAndHumidity lastValues =lecturaDatosDHT22();
  //Envio de los datos
  envioDatosDHT22(String(lastValues.temperature,0),String(lastValues.humidity,0));
  delay(20000);
}
