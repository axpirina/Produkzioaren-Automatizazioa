/* L298P Motor Shield-a
  Motor bat denbora jakin batez Aurrerantz eta gero Atzerantz mugitzen
  duen programa.
  Atzerantz doanean soinua aterako du.  
  2019 ko Azaroan by Axpi
  This example code is in the public domain.
*/

int E1 = 10; //Motorraren Abiadura PWM.
int M1 = 12; // Motorraren Norantza.
int piezoPin=4;

void setup()
{
pinMode(M1, OUTPUT);
Serial.begin(9600);
}

void loop()
{
  { 
  int abiadura;
  for(abiadura = 200 ; abiadura <= 255; abiadura+=1)   // Motorra AURRERANTZ
    {
     digitalWrite(M1,HIGH);
     analogWrite(E1, abiadura);
     delay(200);
     Serial.print("Abiadura: ");
     Serial.println(abiadura);
     Serial.println("FORWARD");
    }
  analogWrite(E1, 0);          // Motorra GERATU 5 sg-duz
  delay(5000);
 }
 
 
 {
  int abiadura;
  for(abiadura = 200 ; abiadura <= 255; abiadura+=1)    // Motorra ATZERANTZ
   {
    digitalWrite(M1,LOW);
    analogWrite(E1, abiadura);
    delay(50);
    Serial.print("Abiadura: ");
    Serial.println(abiadura);
    Serial.println("BACKWARD");
    tone(piezoPin, 1000, 50);       // Tonua egin 
    delay(50);
    tone(piezoPin, 2000, 50);
   }
  analogWrite(E1, 0);          // Motorra GERATU 5 sg-duz
  delay(5000);
  }
}
