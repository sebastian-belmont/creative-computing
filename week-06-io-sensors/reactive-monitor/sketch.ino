// Reactive Monitor
// The Custom Binary Code, but now an ultrasonic sensor decides what gets said.
// The LEDs show a coded reaction to how close someone is.
//
// Rules of the code:
//   000 (all off) = gap between words
//   a new word is only sent when the reaction changes

const int ledPins[] = {8, 9, 10};
const int NUM_LEDS = 3;

const int TRIG_PIN = 6;
const int ECHO_PIN = 7;

const int GAP_TIME = 300;     // all-off gap between words (ms)
const int THANKS_TIME = 1500; // how long "thanks" shows (ms)

// Vocabulary
const int TOO_CLOSE = 0;
const int HELLO = 1;
const int COME_CLOSER = 2;
const int NOBODY = 3;
const int THANKS = 4;

String vocabulary[] = {"too close", "hello", "come closer", "nobody here", "thanks"};

int codes[][3] = {
  {1, 1, 1},  // too close
  {1, 0, 0},  // hello
  {0, 1, 0},  // come closer
  {0, 0, 1},  // nobody here
  {1, 0, 1}   // thanks
};

int lastWord = -1;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

// Send a short pulse and time how long the echo takes to come back
long readDistanceCm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) {
    return 400;  // no echo, treat it as nothing there
  }
  return duration / 58;  // microseconds to centimetres
}

// Turn a distance into a word
int chooseWord(long distance) {
  if (distance < 20) {
    return TOO_CLOSE;
  } else if (distance < 60) {
    return HELLO;
  } else if (distance < 150) {
    return COME_CLOSER;
  } else {
    return NOBODY;
  }
}

void showPattern(const int pattern[]) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], pattern[i] == 1 ? HIGH : LOW);
  }
}

void allOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void sendWord(int wordIndex) {
  allOff();  // gap so you can tell a new word is coming
  delay(GAP_TIME);
  showPattern(codes[wordIndex]);
  Serial.println(vocabulary[wordIndex]);
}

void loop() {
  long distance = readDistanceCm();
  int currentWord = chooseWord(distance);

  if (currentWord != lastWord) {
    // If someone backs off after being too close, say thanks first
    if (lastWord == TOO_CLOSE) {
      sendWord(THANKS);
      delay(THANKS_TIME);
    }
    sendWord(currentWord);
    lastWord = currentWord;
  }

  delay(100);
}
