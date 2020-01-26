#include <Keypad.h>

const int left = A5;
const int right = A4;
const int up = A3;
const int down = A2;
const int Z = A1;
const int start = A0;
const int A = 10;
const int B = 11;
const int X = 12;
const int LR = 13;
char lastKey = "";
const int timeToWait = 500;

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void dancingBlade(int direct) {
  for (int x = 0; x < 4; x++) {
    digitalWrite(direct, HIGH);
    digitalWrite(B, HIGH);
    delay(85);
    digitalWrite(direct, LOW);
    digitalWrite(B, LOW);
    delay(85);
  }
  digitalWrite(down, HIGH);
  digitalWrite(B,HIGH);
  delay(40);
  digitalWrite(down, LOW);
  digitalWrite(B,LOW);
}

void Counter() {
  digitalWrite(down, HIGH);
  delay(10);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(down, LOW);
  digitalWrite(B, LOW);
}

void DolphinSlash() {
  digitalWrite(up, HIGH);
  delay(10);
  digitalWrite(B, HIGH);
  delay(100);
  digitalWrite(up, LOW);
  digitalWrite(B, LOW);
}

void ShieldBreak() {
  digitalWrite(B, HIGH);
  delay(500);
  digitalWrite(B, LOW);
}


void reset() {
  delay(100);
  digitalWrite(LR, HIGH);
  delay(400);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(LR, LOW);
  digitalWrite(A, LOW); 
}

void grabDownThrow() {
  digitalWrite(Z, HIGH);
  delay(200);
  digitalWrite(Z, LOW);
  delay(200);
  digitalWrite(down, HIGH);
  delay(50);
  digitalWrite(down, LOW);

}

void upAir() {
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(up, HIGH);
  delay(100);
  digitalWrite(A, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(up, LOW);
  delay(600);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void dashDance() {
  for (int x = 0; x < 10; x++){
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);
    delay(67);
    digitalWrite(right, LOW);
    digitalWrite(left, HIGH);
    delay(67);
  }
  digitalWrite(left, LOW);
}

void leftNeutral() {
  digitalWrite(left, HIGH);
  delay(150);
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(left, LOW);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(A, LOW);
}

void rightNeutral() {
  digitalWrite(right, HIGH);
  delay(150);
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(right, LOW);
  digitalWrite(A, HIGH);
  delay(450);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void standingBackAirLeft() {
  digitalWrite(right, LOW);
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(left, HIGH);
  digitalWrite(A, HIGH);
  delay(600);
  digitalWrite(left, LOW);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void backAirLeft() {
  digitalWrite(left, HIGH);
  delay(250);
  digitalWrite(left, LOW);
  digitalWrite(right, HIGH);
  delay(50);
  digitalWrite(right, LOW);
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(left, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(left, LOW);
  digitalWrite(A, LOW);
}

void backAirRight() {
  digitalWrite(right, HIGH);
  delay(250);
  digitalWrite(right, LOW);
  digitalWrite(left, HIGH);
  delay(50);
  digitalWrite(left, LOW);
  digitalWrite(X, HIGH);
  delay(50);
  digitalWrite(X, LOW);
  digitalWrite(right, HIGH);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(right, LOW);
  digitalWrite(A, LOW);
}

void smashAttack(int direct, int wait) {
  digitalWrite(A, HIGH);
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(A, LOW);
  digitalWrite(direct, LOW);
  delay(350);
}

void tilt(int direct) {
  digitalWrite(direct, HIGH);
  delay(100);
  button40(A);
  digitalWrite(direct, LOW);
  delay(350);
}

void button40(int direct) {
   digitalWrite(direct, HIGH);
   delay(250);
   digitalWrite(direct, LOW);
}

void womboCombo() {
  button40(start);
  reset();
  delay(200);
  button40(B);
  delay(300);
  rightNeutral();
  delay(200);
  rightNeutral();
  delay(500);
  grabDownThrow();
  delay(300);
  smashAttack(left, 850);
}



void downCombo() {
  button40(start);
  reset();
  delay(200);
  button40(B);
  delay(300);
  button40(right);
  grabDownThrow();
  delay(575);
  upAir();
  delay(50);
  standingBackAirLeft();
  dancingBlade(left);
  
}

void setup() {
  Serial.begin(9600);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(LR, OUTPUT);
  downCombo();
}

void loop() {
  // put your main code here, to run repeatedly:
   char key = customKeypad.getKey();
   if (key == '1') {
     smashAttack(left, 400);
     
   } else if (key == '2') {
     button40(up);
    
   } else if (key == '3') {
     smashAttack(right, 400);
    
   } else if (key == 'A') {
     button40(A);
    
   } else if (key == '4') {
    button40(left);
    
   } else if (key == '5') {
     smashAttack(up, 10); 

   } else if (key == '6') {
     button40(right);
    
   } else if (key == 'B') {
     dancingBlade(right);
   
   } else if (key == '7') {
     tilt(up);
    
   } else if (key == '8') {
     button40(down);

   } else if (key == '9') {
     tilt(down);
    
   } else if (key == 'C') {
     Counter();
   
   } else if (key == '*') {
     downCombo();

   } else if (key == '0') {
     grabDownThrow();
     
   }else if (key == '#' && lastKey == '#') {
     reset();
   } else if (key == '#') {
     button40(start);
   }else if (key == 'D') {
    DolphinSlash();
   }
   if (key != false) {
     lastKey = key;
     Serial.print("key ");
     Serial.print(key);
     Serial.print(" lastKey ");
     Serial.print(lastKey);
     Serial.println(" ");
   }
}
