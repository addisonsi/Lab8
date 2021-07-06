/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/addisonsimon/Lab8/src/Lab8.ino"
#include "oled-wing-adafruit.h"
#include "SparkFun_VCNL4040_Arduino_Library.h"
/*
 * Project Lab_6
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 9 "/Users/addisonsimon/Lab8/src/Lab8.ino"
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
OledWingAdafruit display;
VCNL4040 proximity;
void setup() {
  // Put initialization like pinMode and begin functions here.
  display.setup();
  display.clearDisplay();
  display.display();  // cause the display to be updated
  Serial.begin(9600);
  Wire.begin();
  proximity.begin();
  pinMode(D5, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  display.clearDisplay();
  display.loop();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  int proxValue = proximity.getProximity();
  if(display.pressedA()){
    display.print("The current proximity is: ");
    display.println(proxValue);
    delay(10);
    display.display();
  }
  if(display.pressedB()){
    proxValue = proximity.getProximity();
    if(proxValue >=5000){
        digitalWrite(D6, LOW);
        digitalWrite(D7, LOW);
       digitalWrite(D5, HIGH);
    }
    else if(proxValue >= 100){
      digitalWrite(D6, LOW);
        digitalWrite(D7, HIGH);
       digitalWrite(D5, LOW);
    }
    else{
        digitalWrite(D6, HIGH);
        digitalWrite(D7, LOW);
       digitalWrite(D5, LOW);
    }
  }
  if(display.pressedC()){
        display.println("Found device at: 0x60");
        display.display();
  }
  
}