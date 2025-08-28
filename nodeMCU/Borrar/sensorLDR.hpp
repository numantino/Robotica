/*
 * Clase encargada del control del sensor de la cantidad de luz
 */
#pragma once
#include <DHTesp.h> 

//Constantes
const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ

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
     * @param intensidad dato de la intensidad de luz
     */
    int lecturaNivelLuz(int nivel){    
      return ((long)(1024-nivel)*A*10)/((long)B*Rc*nivel);  //usar si LDR entre GND y A0 
    }
    /**
     * Funcion que nos muestra por consola los datos
	   * @param intensidad dato de la intensidad de luz
     */
    void toConsole(int intensidad){
      Serial.print("Lectura datos sensor LDR: ");
      Serial.print(intensidad);
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
