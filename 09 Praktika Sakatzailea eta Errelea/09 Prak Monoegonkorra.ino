/*              KONTROL  MONOEGONKORRA

   Modified By Axpi 2017
   CC. Creatives Commons.
*/

// Aldagaien deklarazioa      

int botoiaA= 2;
int relay= 13;
int balioaA = 0;

// Sarrera-Irteeren Inizializazioa

void setup() 
  {
 Serial.begin (9600);
 pinMode (botoiaA, INPUT);
 pinMode (relay, OUTPUT);
  }

// Programa nagusia

void loop() 
  {
 balioaA = digitalRead(botoiaA); //Pultsadorea irakurri
 Serial.print ("A Pultsagailuaren balioa=  ");
 Serial.println (balioaA);
 if(balioaA==0){digitalWrite(relay,LOW);}
 else {digitalWrite(relay,HIGH);}
 delay (150); 
}
