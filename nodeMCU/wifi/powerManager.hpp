#pragma once

class PowerManager {
public:
  /**
   * Realizamos el sleep del dispositivo
   * @param milliseconds tiempo de apagado en ms
   */
  void deepSleepMs(uint64_t milliseconds) {
    Serial.print("Durmiendo por ");
    Serial.print(milliseconds);
    Serial.println(" ms...");
    ESP.deepSleep(milliseconds * 1000ULL); // deepSleep recibe microsegundos
  }

  /**
   * Realizamos el sleep del dispositivo
   * @param milliseconds tiempo de apagado en segundos
   */
  void deepSleepSec(uint64_t seconds) {
    deepSleepMs(seconds * 1000ULL);
  }
};
