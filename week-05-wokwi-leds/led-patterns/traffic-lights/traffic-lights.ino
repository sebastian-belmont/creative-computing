// Pattern 1: Traffic lights
// One pattern on its own, repeating forever. The full show is in led-patterns.ino.
// LED 1 = red (pin 25), LED 2 = yellow (pin 26), LED 3 = green (pin 27)

int leds[] = {25, 26, 27};

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  trafficLights();
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
