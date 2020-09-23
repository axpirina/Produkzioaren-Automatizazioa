
/* Ordenagailuaren nteklatu bitartez DC motor bat kontrolatuko dugu.

   F- FORWARD -  Motorra AURRERA
   B--BACKWARD - Motorra ATZERA
   S--STOP -     Motorra GERATU

  by Axpi
  This example code is in the public domain.
*/

#include <AFMotor.h>

// Aukera 4 motorretako bat. Kasu honetan M4 aukeratu da.
AF_DCMotor Motorra(4);

int incomingByte;      // Serie karakterea irakurtzeko aldagaia (ASCII Kodean irakuriko du)

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit Motorshield v1 - DC Motor Diseinua V.1");
  Motorra.setSpeed(200);    // Motorarren abiadura definituko dugu
  Motorra.run(RELEASE);
}

void loop() {
  uint8_t i;

  // Serie monitoreko datuak irakurri
  if (Serial.available() > 0) {
    // buffer-eko hizkirik zaharrena irakurtzen du:
    incomingByte = Serial.read();
    Serial.print("Irakurritako Hizkia:  ");
    Serial.println(incomingByte);
  }

  switch (incomingByte) {
    case 'F':
      Motorra.run(FORWARD);
      break;
    case 'B':
      Motorra.run(BACKWARD);
      break;
    case 'S':
      Motorra.run(RELEASE);
      break;
    default:
      break;
  }
}
