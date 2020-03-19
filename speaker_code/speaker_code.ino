
#include "pitches.h"
boolean runOnce = true;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
};

const int speakerPin = 12;

void sa() {
  // C Scale
  for (int i = 0; i < 17; i++) {
    int g = i;
    if (i >= 8) {
      g = 8 - (i - 8);
    }
    Serial.println(g);
    tone(speakerPin, melody[g]);
    delay(70);
    noTone(speakerPin);
    delay(130);
  }
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (runOnce) {
    sa();
  }
  runOnce = false;
  delay(400);
}
