#include "pitches.h"
const int soundInput = 10;
const int soundPin = A0;
boolean sound = false;

boolean runOnce = true;
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

int duration = 0;
const int halfNote = 500;
const int whole = 1000;
const int quarterNote = 250;
int scaling = 0;
int noteDurations[] = {
  2, 4, 4, 4, 4, 4, 4, 2
};

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (runOnce) {
      // C Scale
      for (int thisNote = 0; thisNote < 17; thisNote++) {    
        int noteDuration = 0;
        
        if (thisNote < 7) {
          noteDuration = 1000 / noteDurations[thisNote];
          tone(soundPin, melody[thisNote], noteDuration);
        } else {
          noteDuration = 1000 / noteDurations[ 16 - thisNote];
          tone(soundPin, melody[ 16 - thisNote], noteDuration);        
        }
  
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(soundPin);
      }
      // Arpeggio
      for( int i = 0; i < 7; i++) {
        int noteDuration = 1000 / noteDurations[0];
  
        if (i == 0) {
          tone(soundPin, melody[scaling], quarterNote);
          scaling += 2;        
        } else if(i < 3) {
          tone(soundPin, melody[scaling + 2], quarterNote);
          scaling += 2;      
        } else if (i > 3 && i != 6) {
          tone(soundPin, melody[scaling - 2], quarterNote);
            scaling -= 2;
        } else if( i == 6) {
          tone(soundPin, melody[scaling -2], halfNote);
        } else if( i == 7) {
          continue;
        } else {
          tone(soundPin, melody[7], quarterNote);      
        }
        if ( i < 6) {
          int pauseBetweenNotes = quarterNote * 1.30;
          delay(pauseBetweenNotes);
          noTone(soundPin);
        } else {
          int pauseBetweenNotes = halfNote * 1.30;
          delay(pauseBetweenNotes);
          noTone(soundPin);
        }
      }
    }
    runOnce = false;
}
