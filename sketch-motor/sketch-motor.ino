#include "motor.h"

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
