/*
 * Clase encargada del control de la bomba de agua
 */
#pragma once
#include <DHTesp.h> 

// Tiempo default de riego (Delay 20 sec.)
const int T_BOMBA=7000;

class BombaAgua {
  private:
    int timer_bomba;
    String nombre;
    int pin;
  public:
    /**
     * Inicializamos la funcion
     * @param id nos indica donde esta conectado el sensor
     * @param n nombre que que queremos poner al dispositivo
     * @param h tiempo de tiego
     */
    void init(uint8_t id, String n, int t = T_BOMBA){
      pin = id;
      timer_bomba = t;
      nombre = n;
      pinMode(id, OUTPUT);
      //Empezamos con la bomba de agua apagada
      releOFF(); 
    }
    /**
     * Actualizamos el valor del tiempo de riego
     * @param t tiempo de riego
     */
    void setTiempoRiego(int t)
    {
      timer_bomba = t;
    }
    /**
     * Actualizamos el valor del nombre
     * @param n nuevo nombre
     */
    void setNombre(String n)
    {
      nombre = n;
    }
    /**
     * Funcion que activa el rele
     */
    void releON()
    {
      digitalWrite(pin, LOW);
    }

    /**
     * Funcion que desactiva el rele
     */
    void releOFF()
    {
      digitalWrite(pin, HIGH);
    }
    /**
     * Funcion con la que vamos a iniciar el riego
     */
    void iniciarRiego()
    {
      Serial.print("Inicio del riego [");
      Serial.print(nombre);
      Serial.println("]");
      //Poner bombas de agua
      releON();
      //esperamos un tiempo
      delay(timer_bomba);
      //Paramos bomba de agua
      releOFF();  
      Serial.println("Fin del riego");
    }
};
