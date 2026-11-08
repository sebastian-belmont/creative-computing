// Pattern 3: Heartbeat
// One pattern on its own, repeating forever. The full show is in led-patterns.ino.
// LED 1 = red (pin 25), LED 2 = yellow (pin 26), LED 3 = green (pin 27)

int leds[] = {25, 26, 27};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  heartbeat();
}

// Turns every LED off
void allOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
}

// Pattern 3: Heartbeat. Two quick flashes, then a pause, 4 times
void heartbeat() {
  for (int beat = 0; beat < 4; beat++) {
    for (int flash = 0; flash < 2; flash++) {
      for (int i = 0; i < 3; i++) digitalWrite(leds[i], HIGH);
      delay(100);
      allOff();
      delay(100);
    }
    delay(600);
  }
}
