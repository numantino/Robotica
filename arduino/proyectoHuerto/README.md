# Proyecto Huerto
Con este proyecto se pretende automatizar el riego.
Ademas se quiere la compatibilidad tanto en un entorno con una placa ArduinoUno como con una placa NodeDCU

## Componentes
* **Rele**, para el control del apagado y encendido de la bomba, es de <span style="color: red;">10v + 1out</span>
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="doc/imgRele.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **NO** = Entrada positiva del dispositivo<br/>
  **COM** = Entrada positiva de la fuente de alimentación<br/>
  **NC** = sin nada
  </p>
</div>

* **Bomba**, encargada de proporcionar el agua, esta ira conectada al rele, para que controle su encendido y apagado
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="doc/imgBomba.png" style="max-width: 200px; margin-right: 20px;">
</div>

* **Bateria**, para dar energia al sistema lo que vamos a usar en este caso es una bateria conectada a una placa solar


## Esquema del proyecto
