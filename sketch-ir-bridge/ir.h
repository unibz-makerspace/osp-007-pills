#ifndef _IR_H
#define _IR_H

#include <Arduino.h>
#include <stdint.h>

class IR {
  void method() {
    }
};

namespace ir {

  static uint8_t _irLedPin = 0;
  static uint8_t _irReceiverPin = 0;
  static uint8_t _irCounter = 0xFF;

  void begin(uint8_t irLedPin, uint8_t irReceiverPin) {
    pinMode(irLedPin, OUTPUT);
    pinMode(irReceiverPin, INPUT_PULLUP);
    _irLedPin = irLedPin;
    _irReceiverPin = irReceiverPin;
  }
  
  // This function sends a 38KHz pulse to the irLedPin for a certain number of
  // microseconds. We'll use this whenever we need to detect an infrared event.
  void pulse(void) {
    int16_t microseconds = 1000; //us.
    uint8_t counter = 0xFF;
    // We'll count down from the number of microseconds we are told to wait.
    //cli();  // Turns off any background interrupts.
    
    while (microseconds > 0) {
      // 38 kHz carrier wave is about 13 microseconds high and 13 microseconds low.
      digitalWrite(_irLedPin, HIGH);
      delayMicroseconds(3);
      if(!digitalRead(_irReceiverPin)) {
        counter--;
      }
      digitalWrite(_irLedPin, LOW);
      delayMicroseconds(3);
      if(!digitalRead(_irReceiverPin)) {
        counter--;
      }
      
      // So 21 microseconds altogether.
      microseconds -= 26;
    }
    //sei();  // Turn interrupts back on
    _irCounter = counter;
  }

  bool isBlocked() {
    const uint8_t THRESHOLD = 0xF0; // 1111 0000 , 15*16 + 0*1 = 240
    return (_irCounter > THRESHOLD);
  }
}

#endif
