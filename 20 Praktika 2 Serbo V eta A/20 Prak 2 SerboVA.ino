/* Serboak kontrolatzeko programa.
    100 Balioan GELDIK
    110 eta 90 balioak MANTSO alde bakoitzera
*/
#include <Servo.h>

int x = 0;
int y = 0;

Servo Horizontala; // Serbo HORIZONTALA objetua sortzen du
Servo Bertikala; // Serbo BERTIKALA objetua sortzen du

int angeluaSerbo2=90;
int gehikuntza=5;            //  Pausu bakoitzean gehituo=ko diren graduak

void setup() {
  Serial.begin(9600);
  Horizontala.attach(9); // Serbo horizontala konektatutzen den Arduino Pin-a
  Bertikala.attach(10); // Serbo horizontala konektatutzen den Arduino Pin-a
}


void loop() {
  x = analogRead(0);
  y = analogRead(1);

  Serial.print("X balioa:   ");
  Serial.println(x);
  Serial.print("Y balioa:   ");
  Serial.println(y);

  Serial.println(" ");

      //-------- 1 SERBOA -- (OINARRIA !!!!) ---------------//----------
      if ((x >= 0) && (x <= 494)) {
        Horizontala.write(80); // Serbo Horizontalaren balioa finkatu
        Serial.print("setServo:    ");
        Serial.println("X ABIADURA -");
      }

      else if ((x > 494) && (x <= 530)) {
        Horizontala.write(90); // Serbo Horizontalaren balioa finkatu
        Serial.print("setServo:    ");
        Serial.println("X ABIADURA 0");
      }

      else if ((x > 530) && (x <= 1024)) {
        Horizontala.write(100); // Serbo Horizontalaren balioa finkatu
        Serial.print("setServo:    ");
        Serial.println("X ABIADURA +");
      }
      //---------- 2 SERBOA ---------------------------
      if ((y >= 0) && (y <= 494)) {
        angeluaSerbo2 = angeluaSerbo2 - gehikuntza;
        angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
        Bertikala.write(angeluaSerbo2);
        Serial.print("setServo:    ");
        Serial.println(angeluaSerbo2);
      }

      else if ((y > 494) && (y <= 530)) {
        Bertikala.write(angeluaSerbo2);
        Serial.print("setServo:    ");
        Serial.println(angeluaSerbo2);
      }

      else if ((y > 530) && (y <= 1024)) {
        angeluaSerbo2 = angeluaSerbo2 + gehikuntza;
        angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
        Bertikala.write(angeluaSerbo2);
        Serial.print("setServo:    ");
        Serial.println(angeluaSerbo2);
      }
 //---------------------------------------------//----------
  delay(0);
}
