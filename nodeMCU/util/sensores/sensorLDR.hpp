/*
 * Clase encargada del control del sensor de la cantidad de luz
 * 
 * Version: 1.0 
 */
#pragma once
#include <DHTesp.h> 

//Resistencia en oscuridad en KΩ
const long RESISTENCIA_A=1000;
//Resistencia a la luz (10 Lux) en KΩ
const int RESISTENCIA_B=15;
//Resistencia calibracion en KΩ
const int RESISTENCIA_Rc=10;

class SensorLDR {
  private:
    uint8_t pin;
  public:
    /**
     * Inicializamos la funcion
     * @param id nos indica donde esta conectado el sensor
     */
    void init(uint8_t id){
      pin = id;
    }
	 /**
      * Funcion que lee el valor del pinLDR
	  * Valores comprendidos entre 0 y 1023. 
	  * @param intensidad dato de la intensidad de luz
      */
	int lecturaNormal(){
		return analogRead(pin);
	}
    /**
     * Funcion que lee el valor del pinLDR, con datos de control
	 * usar si LDR entre GND y A0 
     * @param intensidad dato de la intensidad de luz
     */
    int lecturaNivelLuz(int nivel){    
      return ((long)(1024-nivel)*RESISTENCIA_A*10)/((long)RESISTENCIA_B*RESISTENCIA_Rc*nivel);
    }
    /**
     * Funcion que nos muestra por consola los datos
	 * @param intensidad dato de la intensidad de luz
     */
    void toConsole(int intensidad){
      Serial.print("Lectura datos sensor LDR: ");
      Serial.println(intensidad);
    }
    /**
     * Funcion que nos genera el html que queremos mostrar
	 * @param intensidad dato de la intensidad de luz
     */
    String toHtml(int intensidad){
      String html = "<p>Intensidad de luz: " + String(intensidad) + "</p>";
      return html;
    }
};
