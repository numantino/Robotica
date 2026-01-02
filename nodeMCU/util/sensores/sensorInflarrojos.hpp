/*
 * Clase encargada del control del sensor de inflarrojos
 * Con estos sonsores, minimo dos, se puede seguir una linea
 *
 * Version: 1.0 
 */
#pragma once

class SensorInflarrojos {
  private:
    uint8_t pin;
  public:
    /**
     * Inicializamos la funcion
     * @param id nos indica donde esta conectado el sensor
     */
    void init(uint8_t id){
      pin = id;
      pinMode(id , INPUT);  //definir pin como entrada
    }
    /**
     * @return nos indica si ha encontrado un obstaculo
     */
    bool isObstaculo(){
      int value = 0;
      value = digitalRead(pin);
      return value == HIGH;
    }
};
