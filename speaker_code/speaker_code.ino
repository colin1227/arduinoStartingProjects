
#include "pitches.h"
boolean runOnce = true;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

const int ledPin = 5;
const int speakerPin = A0;
int duration = 0;
const int halfNote = 500;
const int whole = 1000;
const int quarterNote = 250;
int scaling = 0;
int noteDurations[] = {
  2, 4, 4, 4, 4, 4, 4, 2
};

void setup() {
 pinMode(ledPin, OUTPUT);
}

void loop() {
  if (runOnce) {
    // C Scale
    for (int thisNote = 0; thisNote < 17; thisNote++) {    
      int noteDuration = 0;
      
      if (thisNote < 7) {
        noteDuration = 1000 / noteDurations[thisNote];
        tone(speakerPin, melody[thisNote], noteDuration);
      } else {
        noteDuration = 1000 / noteDurations[ 16 - thisNote];
        tone(speakerPin, melody[ 16 - thisNote], noteDuration);        
      }

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(speakerPin);
    }
    // Arpeggio
    for( int i = 0; i < 7; i++) {
      int noteDuration = 1000 / noteDurations[0];

      if (i == 0) {
        tone(speakerPin, melody[scaling], quarterNote);
        scaling += 2;        
      } else if(i < 3) {
        tone(speakerPin, melody[scaling + 2], quarterNote);
        scaling += 2;      
      } else if (i > 3 && i != 6) {
        tone(speakerPin, melody[scaling - 2], quarterNote);
          scaling -= 2;
      } else if( i == 6) {
        tone(speakerPin, melody[scaling -2], halfNote);
      } else if( i == 7) {
        continue;
      } else {
        tone(speakerPin, melody[7], quarterNote);      
      }
      if ( i < 6) {
        int pauseBetweenNotes = quarterNote * 1.30;
        delay(pauseBetweenNotes);
        noTone(speakerPin);
      } else {
        int pauseBetweenNotes = halfNote * 1.30;
        delay(pauseBetweenNotes);
        noTone(speakerPin);
      }
    }
  }
  runOnce = false;
  delay(400);
  digitalWrite(ledPin, HIGH);
}
