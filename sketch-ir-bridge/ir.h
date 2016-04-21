/*
 * Source code for the pill dispenser project of the Liceo Scientifico
 * "Torricelli" Bolzano.
 * A project in collaboration with makerspace - Faculty of Computer Science 
 * at the Free University of Bozen-Bolzano.
 * 
 *                                                                         
 *    m  a  k  e  r  s  p  a  c  e  .  i  n  f  .  u  n  i  b  z  .  i  t  
 *                                                                         
 *   8888888888888888888888888888888888888888888888888888888888888888888888
 *                                                                         
 *                  8                                                      
 *                  8                                                      
 *   YoYoYo. .oPYo. 8  .o  .oPYo. YoYo. .oPYo. 8oPYo. .oPYo. .oPYo. .oPYo. 
 *   8' 8' 8 .oooo8 8oP'   8oooo8 8  `  Yb..`  8    8 .oooo8 8   `  8oooo8 
 *   8  8  8 8    8 8 `b.  8.  .  8      .'Yb. 8    8 8    8 8   .  8.  .  
 *   8  8  8 `YooP8 8  `o. `Yooo' 8     `YooP' 8YooP' `YooP8 `YooP' `Yooo' 
 *                                             8                           
 *                                             8                           
 *                                                                         
 *   8888888888888888888888888888888888888888888888888888888888888888888888
 *                                                                         
 *    c  o  m  p  u  t  e  r    s  c  i  e  n  c  e    f  a  c  u  l  t  y 
 *                                                                         
 *                                                                         
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 Julian Sanin
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _IR_H
#define _IR_H

#include <Arduino.h>
#include <stdint.h>

class Infrared {
public:
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
  // The values are optimzed for an Arduino Uno with stock clock frequency.
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
    //sei();  // Turn interrupts back on.
    _irCounter = counter;
  }

  bool isBlocked() {
    const uint8_t THRESHOLD = 0xF0; // 1111 0000 in binary , 15*16 + 0*1 = 240 in decimal.
    return (_irCounter > THRESHOLD);
  }
}

#endif
