#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(D5, OUTPUT);
}

auto state = HIGH;
void loop() {
  state = state == HIGH ? LOW : HIGH;
    

  // put your main code here, to run repeatedly:
  digitalWrite(D5, state);
  delay(1000);
}