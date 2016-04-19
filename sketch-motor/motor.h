#ifndef _MOTOR_H
#define _MOTOR_H

#include <Arduino.h>
#include <stdint.h>

namespace motor {
  static uint8_t _motorPin = 0;

  void begin(uint8_t motorPin) {
    pinMode(motorPin, OUTPUT);
    digitalWrite(motorPin, LOW);
    _motorPin = motorPin;
  }

  void step(void) {
    for(uint8_t i = 0; i < 1; i++) {
      digitalWrite(_motorPin, HIGH);
      delay(50);
      digitalWrite(_motorPin, LOW);
      delay(100);
    }
  }
}

#endif
