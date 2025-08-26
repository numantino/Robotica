/*
 * Clase encargada del control del sensor de humedad de la tierra
 */
#pragma once
#include <DHTesp.h> 

class SensorYL69 {
  private:
    int humbral;
    uint8_t pin;
    String nombre;
  public:
    /**
     * Inicializamos la funcion
     * @param id nos indica donde esta conectado el sensor
     * @param n nombre que que queremos poner al dispositivo
     * @param h humbral que le indicamos a este dispositivo, DEFAULT_HUMBRAL
     */
    void init(uint8_t id, String n, int h = DEFAULT_HUMBRAL){
      pin = id;
      humbral = h;
      nombre = n;
      pinMode(id, INPUT);
    }
    /**
     * Funcion que puede modificar el humbral
     * @param h nuevo dato del humbral
     */
    void setHumbral(int h){
      humbral = h;
    }
    /**
     * Funcion que puede modificar el nombre
     * @param n nuevo nombre
     */
    void setNombre(String n){
      nombre = n;
    }
    /**
     * @return devuelve la humedad
     */
    float getHumedad(){
      return analogRead(pin);
    }
    /**
     * @return nos indica si el suelo esta seco dependiendo del humbral
     */
    bool isSeco(){
      return getHumedad() >= humbral;
    }
    /**
     * Funcion que nos muestra por consola los datos
     */
    void toConsole(){
      Serial.print("Lectura datos sensor YL69[");
      Serial.print(nombre);
      Serial.print("]: ");
      Serial.print(getHumedad());
      if (isSeco()) Serial.println(" --> necesita regarse");
      else Serial.println(" --> esta humedo, no necesita riego");
    }
    /**
     * Funcion que nos genera el html que queremos mostrar
     */
    String toHtml(){
      String html = "<p>Humedad del suelo: " + String(getHumedad()) + ", del dispositivo: " + String(nombre) + "</p>";
      html += "<p>";
      if(isSeco()) html += "Necesita riego";
      html += "</p>";
      return html;
    }
};
