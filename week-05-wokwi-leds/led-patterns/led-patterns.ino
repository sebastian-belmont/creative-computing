// LED patterns: an ESP32 with three LEDs cycling through four patterns.
// Each pattern runs for about 4 seconds, then the next one starts.
//
// LED 1 = red (pin 25), LED 2 = yellow (pin 26), LED 3 = green (pin 27)

int leds[] = {25, 26, 27};  // the three LED pins, stored in an array

void setup() {
  // Set every LED pin as an output
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  trafficLights();
  wave();
  heartbeat();
  binaryCount();
}

// Turns every LED off
void allOff() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], LOW);
  }
}

// Pattern 1: UK traffic lights (red, red + amber, green, amber)
void trafficLights() {
  allOff();
  digitalWrite(leds[0], HIGH);   // red
  delay(1500);
  digitalWrite(leds[1], HIGH);   // red + amber
  delay(700);
  allOff();
  digitalWrite(leds[2], HIGH);   // green
  delay(1500);
  allOff();
  digitalWrite(leds[1], HIGH);   // amber
  delay(700);
  allOff();
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
