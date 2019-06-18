/*  ----------------------------------------------------------------
 Abiadurazko Serbomotorra bi aldeetara abiadura desberdinetan Automatikoki
 mugitzen duen programa da hurrengoa.

  0   -- Abiadura MAX alde batera
  90  -- Geldirik
  180 -- Abiadura MAX beste aldera
  
  by Axpi
  This example code is in the public domain.

  Eskerrak  https://www.luisllamas.es/controlar-un-servo-de-rotacion-continua-con-arduino/        
    
--------------------------------------------------------------------  
*/
#include <Servo.h>
Servo myservo;  // Serbo objetua sortzen du
int vel = 0;    // Serboaren hasierako abiadura

void setup() {
 Serial.begin(9600);
  myservo.attach(6);      // Serboa 6. pinean konektatu
}

void loop() {

  vel = 90;               //Serboa GELDIRIK
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
  Serial.print(vel);
  Serial.println("   GELDIRIK");
  delay(1500);

  vel = 94;               //Serboa %10 abiaduran alde batera
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
  Serial.print(vel);
  Serial.println("   MANTSO R");
  delay(1500);

  vel = 86;               //Serboa %10 abiaduran beste aldera
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
   Serial.print(vel);
  Serial.println("   MANTSO L");
  delay(1500);

  vel = 90;               //Serboa GELDIRIK
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
  Serial.print(vel);
  Serial.println("   GELDIRIK");
  delay(1500);

  vel = 180;             //Serboa %100 abiaduran alde batera
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
  Serial.print(vel);
  Serial.println("   AZKAR R");
  delay(1500);

  vel = 0;               //Serboa %100 abiaduran beste aldera
  myservo.write(vel);
  Serial.print("Serboaren abiadura:  ");
  Serial.print(vel);
  Serial.println("   AZKAR L");
  delay(1500);
}
