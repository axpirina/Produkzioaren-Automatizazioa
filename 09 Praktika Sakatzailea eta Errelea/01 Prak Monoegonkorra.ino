/*        KONTROL  BIEGONKORRA (Sakatzaile 1)
 
Debounce metodoa aplikatu zaio zarata elektrikoa ekiditeko.
created 21 Nov 2006 by David A. Mellis
modified 20 sep 2018 by Axpi
This example code is in the public domain.
http://www.arduino.cc/en/Tutorial/Debounce
*/
// Aldagaiak definitu
const int buttonPin = 2;
const int ledPin = 8;
int ledState = LOW; // LED-aren hasierako balioa
int buttonState; // Sakatzailearen oraingo egoera
int lastButtonState = LOW; // Sakatzailearen aurreko egoera
 
// DEBOUNCE denborak. 
unsigned long lastDebounceTime = 0; // Lehen aldiz sakatua 
unsigned long debounceDelay = 50; // Debounce denbora. 
 
void setup() {
Serial.begin(9600); // Serie komunikazioa martxan jarri.
pinMode(buttonPin, INPUT);
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, ledState);
Serial.print("Sakatzailea sakatu zain...........");
}
 
void loop() {
int reading = digitalRead(buttonPin);
if (reading != lastButtonState) { //Sakatzailea sakatu
lastDebounceTime = millis();   //Timerra inizializatu
}
// Botoiaren egoera aldatu baldin bada:
if ((millis() - lastDebounceTime) > debounceDelay) {
if (reading != buttonState) {  // Botoia aldatu bada
buttonState = reading; // Balioak eguneratu
if (buttonState == HIGH) {//LED-a HIGH bada soilik
ledState = !ledState;
Serial.print("LED-a: ");
Serial.println(ledState);
}
}
}    
digitalWrite(ledPin, ledState); // LED-a freskatu
lastButtonState = reading; // Balioak eguneratu
}
