#include <Keypad.h>
const int left = 28;
const int right = A4;
const int up = A5;
const int down = A3;
const int Z = 47;
const int start = 44;
const int A = 49;
const int B = 48;
const int Y = 46;
const int LR = 45;
const int RTilt = 43;
const int LTilt = 42;
const int DTilt = 11;
const int UTilt = 12;
char lastKey = "";
const int timeToWait = 500;
boolean runMe = false;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

byte colPins[ROWS] = {2, 3, 4, 5};
byte rowPins[COLS] = {6, 7, 8, 9};

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void button40(int direct, int wait = 40) {
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(direct, LOW);
  delay(40);
}

void tilt(int direct) {
  if (direct == up || direct == down) {
    button40(UTilt);
    digitalWrite(down, HIGH);
    delay(200);
    digitalWrite(down, LOW);
  } else {
    button40(direct);
  }
}

void Uair(int drift = false) {
  //  digitalWrite(Y, HIGH);
  if (drift) {
    digitalWrite(drift, HIGH);
    delay(30);
    digitalWrite(drift, LOW);
  }
  digitalWrite(up, HIGH);
  digitalWrite(A, HIGH);
  delay(50);
  //  digitalWrite(Y, LOW);
  digitalWrite(up, LOW);
  delay(75);
  digitalWrite(down, HIGH);
  digitalWrite(A, LOW);
  delay(85);
  digitalWrite(down, LOW);
  delay(100);
}

void reset() {
  digitalWrite(LR, HIGH);
  delay(300);
  digitalWrite(A, HIGH);
  delay(100);
  digitalWrite(LR, LOW);
  digitalWrite(A, LOW);
  delay(400);
}

void downThrow() {
  digitalWrite(down, HIGH);
  digitalWrite(Z, HIGH);
  delay(40);
  digitalWrite(Z, LOW);
  digitalWrite(down, LOW);
  delay(40);
  digitalWrite(down, HIGH);
  delay(40);
  digitalWrite(down, LOW);

}

void fullHop(int drift = false) {
  digitalWrite(Y, HIGH);
  if (drift) {
    digitalWrite(drift, HIGH);
    delay(25);
    digitalWrite(drift, LOW);
  } else {
    delay(25);
  }

  if (drift) {
    digitalWrite(drift, HIGH);
    delay(195);
    button40(Z);
    digitalWrite(drift, LOW);
    delay(160);
  } else {
    delay(345);
  }
  digitalWrite(Y, LOW);
  downThrow();
}

void shortHop() {
  digitalWrite(Y, HIGH);
  delay(40);
  digitalWrite(Y, LOW);
}

void banana() {
  digitalWrite(down, HIGH);
  digitalWrite(B, HIGH);
  delay(300);
  digitalWrite(down, LOW);
  digitalWrite(B, LOW);
  delay(350);
}


void infinite() {
  button40(right, 865);
  delay(300);
  for (int x = 0; x < 3; x++) {
    banana();
    digitalWrite(40, HIGH);
    delay(20);
    digitalWrite(40, LOW);
    delay(50);
    if (x % 2 == 0) {
      fullHop(left);
    } else {
      fullHop(right);
    }
    delay(200);
    digitalWrite(down, HIGH);
    delay(40);
    digitalWrite(down, LOW);
    delay(100);
  }
}

void smashAttack(int direct, int wait = 200) {
  digitalWrite(A, HIGH);
  digitalWrite(direct, HIGH);
  delay(wait);
  digitalWrite(A, LOW);
  digitalWrite(direct, LOW);
  delay(350);
}

void dashAttack(int direct) {
  digitalWrite(direct, HIGH);
  delay(150);
  button40(A);
  digitalWrite(direct, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(start, OUTPUT);
  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  pinMode(LR, OUTPUT);
//  reset();
//  infinite();
  //  digitalWrite(weakLeft, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = customKeypad.getKey();
  if (key != false) {
    Serial.println(key);
  }
  if (key == '1') {
    reset();
    infinite();

  } else if (key == '2') {
    button40(up, 200);

  } else if (key == '3') {
    tilt(RTilt);
  } else if (key == 'A') {
    button40(A);

  } else if (key == '4') {
    button40(left, 200);

  } else if (key == '5') {
    smashAttack(up, 10);

  } else if (key == '6') {
    button40(right, 200);

  } else if (key == 'B') {
    button40(B);

  } else if (key == '7') {
    tilt(up);

  } else if (key == '8') {
    button40(down, 200);

  } else if (key == '9') {
    tilt(down);

  } else if (key == 'C') {
    if (runMe) {
      shortHop();
      runMe = false;
    } else {
      fullHop();
      runMe = true;
    }

  } else if (key == '*') {
    infinite();

  } else if (key == '0') {

  } else if (key == '#') {
    if (runMe) {
      reset();
      runMe = false;
    } else {
      button40(start);
      runMe = true;
    }

  } else if (key == 'D') {
    reset();
  }

}
