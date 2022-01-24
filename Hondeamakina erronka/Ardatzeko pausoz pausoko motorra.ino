/* Example sketch to control a stepper motor with TB6600 stepper motor driver, AccelStepper library and Arduino 
More info: https://www.makerguides.com 
This code is licensed under a Creative Commons Attribution 4.0 International license. 
modified by Axpi 2021
*/
#include <AccelStepper.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 10
#define stepPin 11
#define motorInterfaceType 1


// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);


int joystickX = 0;

void setup() {
  Serial.begin(9600);
  // Set the maximum speed and acceleration:
  stepper.stop();
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(500);
}
void loop() {

  joystickX = analogRead(0); //  position kontrola

  Serial.print("Joystick-a: (X)  ");
  Serial.println(joystickX);


    while (joystickX < 153 ) {
      // Set the target position:
      stepper.move(500);
      stepper.run();
      joystickX = analogRead(0);
      delay(0);
    }
   while (joystickX > 953 ) {
      // Set the target position:
      stepper.move(-500);
      stepper.run();
      joystickX = analogRead(0);
      delay(0);
   }
 
}
