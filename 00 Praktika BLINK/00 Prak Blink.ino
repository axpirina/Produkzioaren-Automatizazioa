/* Blink
  Arduino UNOaren barne LEDa dir dirka jartzen du segundu batetako maiztasuna eta serial 
  monitorean bere egoera adierazten digu.
  https://www.arduino.cc/en/Main/Products
  modified 8 May 2014
  by Scott Fitzgerald
  dified 03 June 2019
  by Axpi
  This example code is in the public domain.
*/

// Setup funtzioa behin bakarrik exekutatzen da
void setup() {
  // Inizializazio baldintzak jartzen dira bertan
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

// Loop funtzioak behin eta berriz exekutatzen ditu bertako aginduak
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED-a piztu
  Serial.print("LED-a  ");           // Serial monitorean LEDaren egoera idatzi
  Serial.println("ON");
  delay(1000);                       // Segundu bat itxaron
  digitalWrite(LED_BUILTIN, LOW);    // LED-a itzaldu
  Serial.print("LED-a  ");           // Serial monitorean LEDaren egoera idatzi
  Serial.println("OFF");
  delay(1000);                       // Segundu bat itxaron
}
