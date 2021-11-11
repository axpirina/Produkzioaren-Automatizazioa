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
 pinMode (botoia, INPUT);
 pinMode (relay, OUTPUT);
  }

// Programa nagusia

void loop() 
  {
 balioaA = digitalRead(botoiaA); //Pultsadorea irakurri
 Serial.print ("Pultsagailuaren balioa=  ");
 Serial.println (balioa);
 if(balioaA==0){digitalWrite(relay,LOW);}
 else {digitalWrite(relay,HIGH);}
 delay (150); 
}
