/* Example sketch to control a stepper motor with TB6600 stepper motor driver, AccelStepper library and Arduino 
More info: https://www.makerguides.com 
This code is licensed under a Creative Commons Attribution 4.0 International license. 
modified by Axpi 2021
*/
#include <AccelStepper.h>
#include <Wire.h> 
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 10
#define stepPin 11
#define motorInterfaceType 1
#define movementDone 12     // Mugimendua amaitzean errele seinalea bidaltzeko

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

// Sakatzaile, joystick eta balio aldagaien definizioa:
int balioaA = 1;
int balioaB = 1;
int balioaC = 1;
int balioaD = 1;
int joystickY = 0;
int joystickX = 0;
int i = 0;
int target = 12000; // Mugimenduaren ibiltartea !!!!!!!!!!!!!!!!!!!!
float zm = target*0.0015;

int motorState = 0; // motorState = 1 (RUN) eta motorState = 0 (STOP)

void setup() {
  Serial.begin(9600);
  stepper.stop();
  stepper.setMaxSpeed(2000);
  stepper.setAcceleration(500);
}


void loop() {
  joystickY = analogRead(1); //  position kontrola
  joystickX = analogRead(0); //  target kontrola
  Serial.print("(Y):  ");
  Serial.println(joystickY);
  Serial.print("(X):  ");
  Serial.println(joystickX);
  Serial.println(" ");
 

 
    while (joystickY > 953) {
      // Set the target position:
      stepper.move(-1000);
      stepper.run();
      joystickY = analogRead(1);
      delay(0);
    }
    while (joystickY < 153 ) {
      // Set the target position:
      stepper.move(1000);
      stepper.run();
      joystickY = analogRead(1);
      delay(0);
    }
    

    delay(500);
  }
