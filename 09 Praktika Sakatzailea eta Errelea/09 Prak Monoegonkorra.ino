/*              KONTROL  MONOEGONKORRA
 
Hurrengo programak pultsagailu baten irakurketa egiten du eta Irteera bat kontrolatzen du era monoegonkorrean   
   Ondoren Serie Monitorean idazten ditu balioak.

   Modified By Axpi 2017
   CC. Creatives Commons.
*/

// Aldagaien deklarazioa      

int botoia= 2;
int relay= 13;
int balioa = 0;

// Sarrera-Irteeren Inizializazioa

void setup() 
  {
 Serial.begin (9600);
 pinMode (botoia, INPUT);
 pinMode (relay, OUTPUT);
 digitalWrite(relay,HIGH); //Errelea itzali
  }

// Programa nagusia

void loop() 
  {
 balioa = digitalRead(botoia); //Pultsadorea irakurri
 digitalWrite(relay,!balioa); //Errelea kontrolatu
 Serial.print ("Pultsagailuaren balioa=  ");
 Serial.println (balioa);
 delay (150); 
}
