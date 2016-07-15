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

#include <Cmd.h> // Libreria dalla cartella libraries.

/*
 * Circuito di interfaccia del modulo bluetooth:
 * 
 * Arduino Uno      HC-06/05
 * 
 *     5V o-----------o VCC
 * 
 *    GND o--------o--o GND
 *                 |
 *                ---
 *                GND
 *            ___
 *  RX<-0 o--|___|----o TXD
 *          100 Ohm
 *            ___
 *  TX->1 o--|___|-o--o RXD
 *           1kOhm |
 *                .-.
 *                | | 2kOhm
 *                | |
 *                '-'
 *                 |
 *                ---
 *                GND
 */

void setup() {
  // Modulo Bluetooth HC-06/05 connesso su TX e RX dell'Arduino.
  // 3.3V -> Voltage divider 0V-5V -> 0V-3,3V
  // NON è il pin 3,3V!
  Serial.begin(19200); // Preimpostato è normalmente 9600 baud.
  cmdInit(&Serial);
  cmdAdd("ack", ack);
}

void loop() {
  cmdPoll();
}

void ack(int argc, char **argv) {
  digitalWrite(13, HIGH);
  Serial.println("ok");
}
