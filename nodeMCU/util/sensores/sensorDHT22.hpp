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
	 * @param data datos del dispositivo
     */
    void toConsole(TempAndHumidity data){
      Serial.print("Lectura datos sensor DHT22[t= ");
      Serial.print(data.temperature);
      Serial.print("ºC, h= ");
      Serial.print(data.humidity);
      Serial.println("%]");
    }
    /**
     * Funcion que nos genera el html que queremos mostrar
	 * @param data datos del dispositivo
     */
	String toHtml(TempAndHumidity data) {
	  String html = R"rawliteral(
		<!DOCTYPE html><html lang="es">
		<head>
		  <meta charset="UTF-8">
		  <title>DHT22</title>
		  <meta http-equiv='refresh' content='5'>
		  <style>
			body { font-family: Arial; background: #111; color: #fff; text-align:center; }
			.value { font-size: 3rem; font-weight: bold; }
			.temp { color: #ff4c29; }
			.hum { color: #4cd3ff; }
		  </style>
		</head>
		<body>
		  <h1>Sensor DHT22</h1>
	  )rawliteral";

	  html += "<div class='value temp'>" + String(data.temperature, 1) + " °C</div>";
	  html += "<div class='value hum'>" + String(data.humidity, 1) + " %</div>";
	  html += "</body></html>";
	  return html;
	}
};
