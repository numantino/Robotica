# Proyecto Huerto
Con este proyecto se pretende automatizar el riego con una placa NodeDCU.

## Componentes
* **Sensor DHT22**, con este sensor se puede recuperar la temperatura y la humedad ambiente. 
No es necesario para este proyecto, pero con el podremos recuperar datos del ambiente.
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="../doc/sensorDHT22.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **DAT** = Salida de datos del control, el que nos informa<br/>
  **VCC** = Alimentacion, no necesita extra, se peude conectar a 3v o 5v<br/>
  **GND** = Alimentacion, tierra
  </p>
</div>

* **Sensor YL69**, con este sensor se controla la humedad de la tierra, consta de dos componentes, el primero que se clavaria en la tierra (es el que es en forma de U) y el segundo componente que es el que realiza el procesamiento
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="../doc/sensorYL69.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **A0** = Salida de datos del control, el que nos informa<br/>
  *D0** = sin nada<br/>
  **VCC** = Alimentacion, no necesita extra, se peude conectar a 3v o 5v<br/>
  **GND** = Alimentacion, tierra
  </p>
</div>

* **Rele**, para el control del apagado y encendido de la bomba, es de <span style="color: red;">10v + 1out</span>
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="../doc/imgRele.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **NO** = Entrada positiva del dispositivo<br/>
  **COM** = Entrada positiva de la fuente de alimentación<br/>
  **NC** = sin nada
  </p>
</div>

* **Bomba**, encargada de proporcionar el agua, esta ira conectada al rele, para que controle su encendido y apagado
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="../doc/imgBomba.png" style="max-width: 200px; margin-right: 20px;">
</div>

* **Bateria**, para dar energia al sistema lo que vamos a usar en este caso es una bateria conectada a una placa solar


## Esquema del proyecto
