/*
 * Clase encargada del control del sensor de ultrasonidos
 * Es un dispositivo con el que se pueden medir distancias
 *
 * Version: 1.0 
 */
#pragma once

#include <NewPing.h>

//Valor de la maxima distancia
const long MAX_DISTANCIA=200;

class SensorHCSR04 {
  private:
    NewPing sonar;
  public:
    /**
     * Constructor de la funcion
     * @param trigger pin del trigger
     * @param echo pin del echo
     */
    SensorHCSR04(uint8_t trigger, uint8_t echo) 
      : sonar(trigger, echo, MAX_DISTANCIA) {}
	  /**
     * Funcion que lee el valor del pinLDR
	   * Valores comprendidos entre 0 y 1023. 
	   * @param intensidad dato de la intensidad de luz
     */
	  int getDistancia(){
		  return sonar.ping_cm();
	  }
    /**
     * Funcion que nos muestra por consola los datos
	   * @param distancia dato de la distancia
     */
    void toConsole(int distancia){
      Serial.print("Lectura datos sensor Ultrasonido: ");
      Serial.print(distancia);
      Serial.println("cm.");
    }
    /**
     * Funcion que nos genera el html que queremos mostrar
	   * @param intensidad dato de la distancia
     */
    String toHtml(int distancia){
      String html = "<p>Distancia de " + String(distancia) + "cm.</p>";
      return html;
    }
};
