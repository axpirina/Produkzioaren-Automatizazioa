/* Serbomotor bat joystick bitartez kontrolatzeko programa.
  by Axpi
  This example code is in the public domain.
*/
#include <Servo.h>

int x = 0;
int angelua = 0;

Servo Horizontala; // Horizontala Serbo objetua sortzen du

int angeluaSerbo = 90;

void setup() {
  Serial.begin(9600);
  Horizontala.attach(11); // Serbo horizontala konektatutzen du Arduinoko 6. Pin-era
}

void loop() {
  
  x = analogRead(0);           // Irakurketa 10 bit-etan (0-1023) balio artean
  
  angelua = map(x, 0, 1023, 0, 180); // Serie monitorean Serboren angelua idatzi
  Serial.print("Serbo angelua:   ");
  Serial.println(angelua);
  Serial.println(" ");
  
  Horizontala.write(angelua);
  
  delay(0);
}
