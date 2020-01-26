#include "pitches.h";
boolean runOnce = true;
int iterate = 3;
const int lightArray[] = {
  7, 9, 11 
};
const int soundArray[] = {
   A0, A2, A4
};

const int upDown[] = {
  NOTE_C3, NOTE_C4, NOTE_C5
};

int current = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    for( int i = 0; i < 9; i++) {
      if (i < 3) {
        digitalWrite(lightArray[i], HIGH);
        tone( soundArray[i], upDown[i]);
        current = soundArray[i];
        if( i > 0) {
          delay(125);
          noTone(soundArray[i - 1]);
          digitalWrite(lightArray[i - 1], LOW);
        }
        
      } else if ( i == 3) {
        delay(125);
        noTone(soundArray[2]);
        digitalWrite(lightArray[2], LOW);
        
      } else if (i < 7) {
        tone(soundArray[6 - i], upDown[6 - i]);
        current = soundArray[6 - i];
        digitalWrite(lightArray[6 - i], HIGH);
        if (i > 4){
          delay(125);
          noTone(soundArray[i - iterate]);
          digitalWrite(lightArray[i - iterate], LOW);
          iterate += 2;
        }
        
      } else if (i == 7) {
        delay(125);
        noTone(soundArray[0]);
        digitalWrite(lightArray[0], LOW);
        
      } else {
        digitalWrite(lightArray[0], HIGH);
        digitalWrite(lightArray[1], HIGH);
        digitalWrite(lightArray[2], HIGH);
        
      }
      delay(125);
      noTone(current);
    }
    delay(125);
    tone(A0, 305);
    delay(120);
    noTone(A0);
    
    tone(A4, 305);
    delay(120);
    noTone(A4);
    
    tone(A2, 305);
    delay(120);
    noTone(A2);
  digitalWrite(lightArray[0], LOW);
  digitalWrite(lightArray[1], LOW);
  digitalWrite(lightArray[2], LOW);
  iterate = 3;
  delay(250);
}
