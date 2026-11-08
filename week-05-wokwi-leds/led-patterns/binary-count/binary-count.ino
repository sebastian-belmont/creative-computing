// Pattern 4: Binary counting
// One pattern on its own, repeating forever. The full show is in led-patterns.ino.
// LED 1 = red (pin 25), LED 2 = yellow (pin 26), LED 3 = green (pin 27)

int leds[] = {25, 26, 27};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  binaryCount();
}

// Turns every LED off
void allOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
}

// Pattern 4: Binary counting. The LEDs show the numbers 0 to 7 in binary
void binaryCount() {
  for (int number = 0; number < 8; number++) {
    for (int i = 0; i < 3; i++) {
      // Is bit i of the number a 1? Then that LED is on
      if (bitRead(number, i) == 1) {
        digitalWrite(leds[i], HIGH);
      } else {
        digitalWrite(leds[i], LOW);
      }
    }
    delay(500);
  }
  allOff();
}
