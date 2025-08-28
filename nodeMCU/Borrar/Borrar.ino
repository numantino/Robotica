#include "SensorLDR.hpp"

#define PIN_LDR A0    //Seleccionamos el pin analógico A0 como input del sensor LDR. 

SensorLDR sensorLdr;

void setup() { 
  Serial.begin(9600); //Inicializamos monitor serie para visualizar los valores de LDR. 
  sensorLdr.init(PIN_LDR);
}

void loop() { 
  delay(1000);                          // esperar un segundo  

  int valor = sensorLdr.lecturaNormal();
  sensorLdr.toConsole(valor);
  sensorLdr.toConsole(sensorLdr.lecturaNivelLuz(valor));
}
