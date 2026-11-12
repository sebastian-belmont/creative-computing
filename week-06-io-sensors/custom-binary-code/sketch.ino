// Custom Binary Code
// Three LEDs act as a tiny "screen". Each ON/OFF pattern stands for a word.
//
// Rules of the code:
//   000 (all off)  = gap between words
//   111 (all on)   = end of message (flashes twice)
//   the other 6 patterns = words in the vocabulary below

const int ledPins[] = {8, 9, 10};
const int NUM_LEDS = 3;

const int WORD_TIME = 1500;  // how long each word stays on (ms)
const int GAP_TIME = 500;    // all-off gap between words (ms)

// Vocabulary:
String vocabulary[] = {"hi", "yes", "no", "brb", "help", "ggwp"};

int codes[][3] = {
  {1, 0, 0},  // hi
  {0, 1, 0},  // yes
  {0, 0, 1},  // no
  {1, 1, 0},  // brb
  {0, 1, 1},  // help
  {1, 0, 1}   // ggwp
};

// The message to send, as positions in the vocabulary (hi, brb, help, ggwp)
int message[] = {0, 3, 4, 5};
const int MESSAGE_LENGTH = 4;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void showPattern(const int pattern[]) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], pattern[i] == 1 ? HIGH : LOW);
  }
}

void allLeds(int state) {
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], state);
  }
}

void endOfMessage() {
  for (int i = 0; i < 2; i++) {
    allLeds(HIGH);
    delay(300);
    allLeds(LOW);
    delay(300);
  }
}

void loop() {
  Serial.println("--- message start ---");

  for (int i = 0; i < MESSAGE_LENGTH; i++) {
    int wordIndex = message[i];
    Serial.println(vocabulary[wordIndex]);
    showPattern(codes[wordIndex]);
    delay(WORD_TIME);

    allLeds(LOW);  // gap so you can tell where one word ends
    delay(GAP_TIME);
  }

  endOfMessage();
  Serial.println("--- end ---");
  delay(2000);
}
