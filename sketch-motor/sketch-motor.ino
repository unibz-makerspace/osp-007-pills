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

#include "motor.h"

/*
 * Circuito di interfaccia del motore riciclato:
 * 
 * Arduino Uno      Motore
 * 
 *     5V o-----------o +
 * 
 *    GND o--------o--o -
 *                 |
 *                ---
 *                GND            
 *            ___
 *     11 o--|___|-o--o A
 *           1kOhm |
 *                .-.
 *                | | 1kOhm
 *                | |
 *                '-'
 *                 |
 *                ---
 *                GND
 *                   -o B (Non Usato)
 */

// Motore riciclato. Purtroppo non ritorna qualche segnale
// per leggere quanto via ha fatto.
// Il motore ha 4 contatti: A B + -
// +         -> 5V  alimentazione
// -         -> GND alimentazione
// A IDLE:5V -> 0V con Arduino output su LOW spegne il motore,
//              altrimenti è accesso.
// B IDLE:5V -> Non reagisce su LOW, molto probabile che è 
//              qualche feedback!?

enum {
  MOTOR_PIN = 11
};

void setup() {
  motor::begin(MOTOR_PIN);
}

void loop() {
  motor::step();
  delay(1000);
}
