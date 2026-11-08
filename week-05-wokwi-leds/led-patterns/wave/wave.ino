// Pattern 2: Wave
// One pattern on its own, repeating forever. The full show is in led-patterns.ino.
// LED 1 = red (pin 25), LED 2 = yellow (pin 26), LED 3 = green (pin 27)

int leds[] = {25, 26, 27};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  wave();
}

// Turns every LED off
void allOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
}

// Pattern 2: Wave. One light runs left to right, then back, 3 times
void wave() {
  for (int rep = 0; rep < 3; rep++) {
    for (int i = 0; i < 3; i++) {      // left to right
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }
    for (int i = 2; i >= 0; i--) {     // right to left
      digitalWrite(leds[i], HIGH);
      delay(200);
      digitalWrite(leds[i], LOW);
    }
  }
}
