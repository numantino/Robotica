#include "conf.h"
#include "sensores.h"
#include "sensorYL69.hpp"
#include "bombaAgua.hpp"

SensorYL69 sensorYL69;
BombaAgua bombaAgua;

void setup() {
  //Inicializacion logs
  Serial.begin(115200);
  //Iniciamos el sensor de la humedad de la tierra
  sensorYL69.init(SENSOR_YL69, "planta1");
  //Inicializamos el rele
  bombaAgua.init(RELE_1, "bomba1");
}

void loop() {
  //Esto es una prueba por consola todo
  sensorYL69.toConsole();
  bombaAgua.iniciarRiego();
  delay(20000);
}
