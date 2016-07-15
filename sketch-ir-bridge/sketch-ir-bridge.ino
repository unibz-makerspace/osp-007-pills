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
 */

#include "ir.h" // Library from your sketch available on top of your "tab" bar.

/*
 * Interfacing circuit of the infrared bridge:
 * 
 * Arduino Uno   Infrared Bridge 
 * 
 *     5V o------------------o--------.
 *                           |        |
 *                           |       .-.
 *            ___       IR   |       | | 1kOhm
 *     13 o--|___|-.    RECV | VCC   | |
 *           1kOhm |       .---.     '-'
 *                 -       |   | OUT  |
 *         IR LED  V ->  ->|   |------o
 *                 -       |___|      |
 *                 |         | GND    |
 *    GND o--------o---------'        |
 *                                    |
 *     12 o---------------------------'
 */

enum {
  IR_RECEIVER_PIN = 12,
  IR_LED_PIN = 13,
  BAUD_RATE = 115200
};

Infrared infrared;

void setup() {
  ir::begin(IR_LED_PIN, IR_RECEIVER_PIN);
  Serial.begin(BAUD_RATE);
}

void loop() {
  infrared.method(); // infrared is a object, therefore use dot operator ".".
  ir::pulse();       // ir is a namespace, therefore use scope operator "::".
  Serial.println(ir::isBlocked() ? "true" : "false");
  delay(1000);
}
