
// Example 1 - Receiving single characters

char receivedChar;
boolean newData = false;

void setup() {
    pinMode(7, OUTPUT); 
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvOneChar();
    showNewData();
}

void recvOneChar() {
    if (Serial.available() > 0) {
        receivedChar = Serial.read();
        newData = true;
    }
}

void showNewData() {
    if (newData == true) {
        digitalWrite(7, HIGH);
        Serial.print("This just in ... ");
        Serial.println(receivedChar);
        newData = false;
        delay(800);
        digitalWrite(7, LOW);
    }
}
