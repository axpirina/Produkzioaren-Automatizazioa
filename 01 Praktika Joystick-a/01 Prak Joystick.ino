/* Serbomotor bat joystick bitartez kontrolatzeko programa.
  by Axpi
  This example code is in the public domain.
*/

int x = 0;
int y = 0;

int A = 0;
int C = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  x = analogRead(0);
  y = analogRead(1);
 
  Serial.print("X ardatza:   ");
  Serial.println(x);
  Serial.print("Y ardatza:   ");
  Serial.println(y);
  Serial.println(" ");
  
  A = digitalRead(2);
  C = digitalRead(4);
  
  Serial.print("A botoia:   ");
  Serial.println(A);
  Serial.print("C botoia:   ");
  Serial.println(C);
  Serial.println(" ");
  
  delay(500);
}
