#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/*
This program is an abridged version of Adafruit BNO055 rawdata.ino available after installing the Adafruit BNO055 library
File→Examples→Adafruit BNO055→Raw Data
  Connections on Arduino Uno
  =========================================================================
  SCL to Serial 3 | SDA to Serial 2 | VDD to 3V DC | GND to common ground
*/

// 45 for cardinal directions, 22.5 for all 8 shits
const int positive = 45;
const int negative = -45;

/* LED's to make it pretty but directions are also given by the Serial Monitor as well */
const int northLight = 8;
const int eastLight = 9;
const int southLight = 11;
const int westLight = 12;

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


//#define BNO055_SAMPLERATE_DELAY_MS (100)          // Delay between data requests

Adafruit_BNO055 bno = Adafruit_BNO055();          // Create sensor object bno based on Adafruit_BNO055 library
void setup(void)
{
  Serial.println("setup");
  if(!bno.begin())                                // Initialize sensor communication
  {  
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");  
  } else {
    Serial.println("asdf");
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
//    usual vals: max = 24 , min = -26
    magnoNorthX = magnoReadingX;  
    if (magnoNorthX > 22) {
       Serial.print("Calibrated");
       Serial.println(" ");
      initalGyrometrics = true; 
      calibrated = true;
      
    } else if (magnoNorthX <= 22){
       Serial.print(magnoNorthX);
       Serial.println(" ");
    } else {
       Serial.print(magnoNorthX);
       Serial.print(" Interference!");
       Serial.println(" ");
    }
  }

  /* Calibration */
  if (initalGyrometrics) {
    digitalWrite(northLight, HIGH);
    digitalWrite(westLight, HIGH);
    digitalWrite(southLight, HIGH);
    digitalWrite(eastLight, HIGH);
    delay(1000);
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
    }
    initalGyrometrics = false;

     Serial.print(" Intial gyrometrics");
     Serial.println(" ");
     
     Serial.print("NORTH: ");
     Serial.print(gyroNorthX);
     Serial.print(",   ");

     Serial.print("EAST: ");
     Serial.print(gyroEastX);
     Serial.print(",   ");

     Serial.print("SOUTH: ");    
     Serial.print(gyroSouthX);
     Serial.print(",   ");

     Serial.print("WEST: ");
     Serial.print(gyroWestX);
    Serial.println(" ");
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
    
   if (gyroNorthX - gyroReadingX >= negative && gyroNorthX - gyroReadingX <= positive) {
        digitalWrite(northLight, HIGH);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, LOW);
         Serial.print("NORTH");
         Serial.println(" ");
    }

    /* NORTH-EAST DETECTION */
    
//    if (gyroNorthEastX - gyroReadingX >= negative && gyroNorthEastX - gyroReadingX <= positive) {
//        digitalWrite(northLight, HIGH);
//        digitalWrite(westLight, HIGH);
//        digitalWrite(southLight, LOW);
//        digitalWrite(eastLight, LOW);
//        // Serial.print("NORTH-EAST");
//        // Serial.println(" ");
//    }

  
    /* EAST DETECTION */
    
   if (gyroEastX - gyroReadingX >= negative && gyroEastX - gyroReadingX <= positive) {
       digitalWrite(northLight, LOW);
       digitalWrite(westLight, HIGH);
       digitalWrite(southLight, LOW);
       digitalWrite(eastLight, LOW);
       Serial.print("EAST");
       Serial.println(" ");
   }


    /* SOUTH-EAST DETECTION */

//   if (gyroSouthEastX - gyroReadingX >= negative && gyroSouthEastX - gyroReadingX <= positive) {
//        digitalWrite(northLight, LOW);
//        digitalWrite(westLight, HIGH);
//        digitalWrite(southLight, HIGH);
//        digitalWrite(eastLight, LOW);
//        Serial.print("SOUTH-EAST");
//        Serial.println(" ");
//   }
// 

    /* SOUTH DETECTION */

   if (gyroSouthX - gyroReadingX >= negative && gyroSouthX - gyroReadingX <= positive) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, HIGH);
        digitalWrite(eastLight, LOW);
        Serial.print("SOUTH");
        Serial.println(" ");
    }


    /* SOUTH-WEST DETECTION */

//    if (gyroSouthWestX - gyroReadingX >= negative && gyroSouthWestX - gyroReadingX <= positive) {
//        digitalWrite(northLight, LOW);
//        digitalWrite(westLight, LOW);
//        digitalWrite(southLight, HIGH);
//        digitalWrite(eastLight, HIGH);
//        Serial.print("SOUTH-WEST");
//        Serial.println(" ");
//     }


    /* WEST DETECTION */

    if (gyroWestX - gyroReadingX >= negative && gyroWestX - gyroReadingX <= positive) {
        digitalWrite(northLight, LOW);
        digitalWrite(westLight, LOW);
        digitalWrite(southLight, LOW);
        digitalWrite(eastLight, HIGH);
         Serial.print("WEST");
         Serial.println(" ");
    }
  

    /* NORTH-WEST DETECTION */
//    if (gyroNorthWestX - gyroReadingX >= negative && gyroNorthWestX - gyroReadingX <= positive) {
//        digitalWrite(northLight, HIGH);
//        digitalWrite(westLight, LOW);
//        digitalWrite(southLight, LOW);
//        digitalWrite(eastLight, HIGH);
//        Serial.print("NORTH-WEST");
//        Serial.println(" ");
//    }
    // Pause before capturing new data             
  }
}
