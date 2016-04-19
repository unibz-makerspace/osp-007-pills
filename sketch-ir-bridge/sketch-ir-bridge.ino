#include "ir.h"
#include "hello.h"

enum {
  IR_RECEIVER_PIN = 12,
  IR_LED_PIN = 13,
  BAUD_RATE = 115200
};

//IR ird;

void setup() {
  ir::begin(IR_LED_PIN, IR_RECEIVER_PIN);
  Serial.begin(BAUD_RATE);
  //ird.method();
  //Serial.println()
}

void loop() {
  ir::pulse();
  Serial.println(ir::isBlocked() ? "true" : "false");
  delay(1000);
}
