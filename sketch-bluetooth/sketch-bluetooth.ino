#include <Cmd.h>

void setup() {
  Serial.begin(19200);
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
