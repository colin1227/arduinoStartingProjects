#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include "pitches.h"

/*
This program is an abridged version of Adafruit BNO055 rawdata.ino available after installing the Adafruit BNO055 library
File→Examples→Adafruit BNO055→Raw Data
  Connections on Arduino Uno
  =========================================================================
  SCL to analog 5 | SDA to analog 4 | VDD to 3.3V DC | GND to common ground
*/

/* sound control */
// PWM for sound 5V
const int soundInput = 10;
const int soundPin = A0;
boolean sound = true;

boolean runOnce = true;
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, 523
};

int duration = 0;
const int halfNote = 500;
const int whole = 1000;
const int quarterNote = 250;
int scaling = 0;
int noteDurations[] = {
  2, 4, 4, 4, 4, 4, 4, 2
};

/* LED's to make it pretty but directions are also given by the Serial Monitor as well */
const int northLight = 8;
const int eastLight = 9;
const int southLight = 12;
const int westLight = 6;

boolean calibrated = false;
boolean initalGyrometrics = false;

/* first value reported is what the calibration of the IMU is set to.
 * Tn that case, if the 360º values can be mapped to the magnetometer readings to make a compass!
 */
int gyroNorthX = 0;

int gyroSouthX = 0;

int gyroEastX = 0;

int gyroWestX = 0;

/* these values of the magnetometer will calibrate the code, anything drasticly higher means
 *  there is an external magnetic force screwing things up and the arduino should be reset.
 */
int magnoNorthX = 0;

int magnoEastWestX = 0;

int magnoSouthX = 0;


#define BNO055_SAMPLERATE_DELAY_MS (100)          // Delay between data requests

Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);          // Create sensor object bno based on Adafruit_BNO055 library

void setup(void)
{
  Serial.begin(9600);                           // Begin serial port communication
  if(!bno.begin())                                // Initialize sensor communication
  {  
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");  
  }
  delay(1000);
  bno.setExtCrystalUse(false);                     // Use the crystal on the development board
}

void loop(void)
{
  imu::Vector<3> magnetometer = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);

  sensors_event_t event; 
  bno.getEvent(&event);

  int gyroReadingX = event.orientation.x;
  int magnoReadingX = magnetometer.x();

    if (magnoReadingX <= 24 && calibrated != true){
//    ussual vals: max = 24 , min = -26
    magnoNorthX = magnoReadingX;  
    if (magnoNorthX > 19) {
       Serial.print("Calibrated");
       Serial.println(" ");
      initalGyrometrics = true; 
      calibrated = true;
      
    } else if (magnoNorthX <= 19){
       Serial.print(magnoReadingX);
       Serial.println(" ");
    } else {
      // Serial.print(magnoNorthX);
      // Serial.print(" Interference!");
      // Serial.println(" ");
    }
  }

  /* Calibration */
  if (initalGyrometrics) {
    
    /* Fancy Light/Sound Show */
    if (runOnce) {
        // C Scale
        for (int thisNote = 0; thisNote < 15; thisNote++) { 
          Serial.print(thisNote);  
          Serial.print(" ");
          Serial.print(melody[thisNote]);
          Serial.print(" ");
          Serial.print( 1000/ noteDurations[thisNote]);  
          Serial.println(" ");
          int noteDuration = 0;
          
          if (thisNote < 8) {
            noteDuration = 1000 / noteDurations[thisNote];
            tone(soundPin, melody[thisNote], noteDuration);
          } else {
            noteDuration = 1000 / noteDurations[ 14 - thisNote];
            tone(soundPin, melody[ 14 - thisNote], noteDuration);        
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
    digitalWrite(northLight, HIGH);
    digitalWrite(westLight, HIGH);
    digitalWrite(southLight, HIGH);
    digitalWrite(eastLight, HIGH);
    delay(300);
    noTone(soundPin);
    digitalWrite(northLight, LOW);
    digitalWrite(westLight, LOW);
    digitalWrite(southLight, LOW);
    digitalWrite(eastLight, LOW);



    
    gyroNorthX = gyroReadingX;
    gyroEastX = gyroReadingX + 90;
    gyroWestX = gyroReadingX - 90;
    gyroSouthX = gyroReadingX - 180;
    if (gyroNorthX > 90) {
      if (gyroEastX > 360) {
        gyroEastX -= 360;
      }
      if (gyroEastX > 360) {
        gyroEastX = gyroEastX - 360;
      }
      if (gyroSouthX < 0) {
        gyroSouthX *= -1;
      }
    } else if (gyroNorthX < 90) {
      gyroWestX += 360;
      gyroSouthX += 360;
    } else if (gyroNorthX > 270) {
      gyroEastX -= 360;
    } else {
    }
    initalGyrometrics = false;

    // Serial.print(" INITAL");
    // Serial.println(" ");
    
    // Serial.print(gyroNorthX);
    // Serial.print(" NORTH ");
    
    // Serial.print(gyroEastX);
    // Serial.print(" EAST ");
    
    // Serial.print(gyroSouthX);
    // Serial.print(" SOUTH ");
    
    // Serial.print(gyroWestX);
    // Serial.print(" WEST ");
    
    // Serial.println(" ");
  }
  
  if (calibrated) {
    if (gyroReadingX < 22.5) {
      gyroReadingX += 360;
    } else if (gyroReadingX > 337.5) {
      gyroReadingX -= 360;
    } else {
    }
  
    int gyroNorthEastX = gyroNorthX + 45;
    int gyroSouthEastX = gyroNorthX + 135;
    int gyroSouthWestX = gyroNorthX - 135;
    int gyroNorthWestX = gyroNorthX - 45;
  
    
    if (gyroNorthEastX > 360) {
      gyroNorthEastX = gyroNorthEastX - 360;
    }
    if (gyroSouthEastX > 360) {
      gyroSouthEastX = gyroSouthEastX - 360;
    }
    if (gyroSouthWestX < 0) {
      gyroSouthWestX = gyroSouthWestX + 360;
    }
    if (gyroNorthWestX < 0) {
      gyroNorthWestX = gyroNorthWestX + 360;
    }
  
    
    /* NORTH DETECTION */
    
   if (gyroNorthX - gyroReadingX >= -22.5 && gyroNorthX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, HIGH);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, LOW);
        // Serial.print("NORTH2");
        // Serial.println(" ");
    }


    /* NORTH-EAST DETECTION */
    
    if (gyroNorthEastX - gyroReadingX >= -22.5 && gyroNorthEastX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, HIGH);
        digitalWrite(westLight, HIGH);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, LOW);
        // Serial.print("NORTH-EAST");
        // Serial.println(" ");
    }

  
    /* EAST DETECTION */
    
   if (gyroEastX - gyroReadingX >= -22.5 && gyroEastX - gyroReadingX <= 22.5) {
       digitalWrite(northLight, LOW);
       digitalWrite(westLight, HIGH);
       digitalWrite(southLight, LOW);
       digitalWrite(eastLight, LOW);
       // Serial.print("EAST");
       // Serial.println(" ");
   }


    /* SOUTH-EAST DETECTION */

   if (gyroSouthEastX - gyroReadingX >= -22.5 && gyroSouthEastX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, HIGH);
        digitalWrite(southLight, HIGH);
        digitalWrite(eastLight, LOW);
        // Serial.print("SOUTH-EAST");
        // Serial.println(" ");
       } else {
        digitalWrite(A1, LOW);
  }
 

    /* SOUTH DETECTION */

   if (gyroSouthX - gyroReadingX >= -22.5 && gyroSouthX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, HIGH);
        digitalWrite(eastLight, LOW);
        // Serial.print("SOUTH");
        // Serial.println(" ");
       }


    /* SOUTH-WEST DETECTION */

    if (gyroSouthWestX - gyroReadingX >= -22.5 && gyroSouthWestX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, HIGH);
        digitalWrite(eastLight, HIGH);
        // Serial.print("SOUTH-WEST");
        // Serial.println(" ");
       } else {
        digitalWrite(A1, LOW);
    }


    /* WEST DETECTION */

    if (gyroWestX - gyroReadingX >= -22.5 && gyroWestX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, HIGH);
        // Serial.print("WEST2");
        // Serial.println(" ");
       }
  

    /* NORTH-WEST DETECTION */
    if (gyroNorthWestX - gyroReadingX >= -22.5 && gyroNorthWestX - gyroReadingX <= 22.5) {
        digitalWrite(northLight, HIGH);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, HIGH);
        // Serial.print("NORTH-WEST");
        // Serial.println(" ");
       } else {
        digitalWrite(A1, LOW);
    }
  
  
    // Pause before capturing new data 
    delay(BNO055_SAMPLERATE_DELAY_MS); 
    }             
  }
