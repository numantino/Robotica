/*
 * Clase encargada del control del sensor de humedad y temperatura ambiente
 */
#pragma once
#include <DHTesp.h> 

class SensorDHT22 {
  private:
    DHTesp dht;
  public:
    /**
     * Inicializamos la funcion
     * @param id nos indica donde esta conectado el sensor
     */
    void init(uint8_t id){
      dht.setup(id, DHTesp::DHT22);
    }
    /**
     * Recupera los datos del sensor
     * @return valores del sensor
    */
    TempAndHumidity leer(){
      return dht.getTempAndHumidity();
    }
    /**
     * @return devuelve la temperatura
     */
    float getTemperatura(){
      return leer().temperature;
    }
    /**
     * @return devuelve la humedad
     */
    float getHumedad(){
      return leer().humidity;
    }
    /**
     * Funcion que nos muestra por consola los datos
     */
    void toConsole(){
      Serial.print("Lectura datos sensor DHT22[t= ");
      Serial.print(getTemperatura());
      Serial.print("ºC, h= ");
      Serial.print(getHumedad());
      Serial.println("%]");
    }
    /**
     * Funcion que nos genera el html que queremos mostrar
     */
    String toHtml(){
      TempAndHumidity data = leer();
      String html = "<!DOCTYPE html><html><head><title>DHT22</title>";
            html += "<meta http-equiv='refresh' content='5'>";
            html += "</head><body>";
            html += "<h1>Sensor DHT22</h1>";
            html += "<p>Temperatura: " + String(data.temperature, 1) + " °C</p>";
            html += "<p>Humedad: " + String(data.humidity, 1) + " %</p>";
            html += "</body></html>";
      return html;
    }
};
