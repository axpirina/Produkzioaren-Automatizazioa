/* Serboak kontrolatzeko programa.
Serbo Shield-a erabiliaz
2018ko Abenduak 09an by Axpi -> modify By UNFERMAI (3.taldea) 2019 ko urtarrilean
Kode hau Creatives Commons lizentziapena argitaratzen da.
*/#include <Wire.h>
#include <Adafruit_PWMServoDriver.h> // programa honetan behar ditugun liburutegiak
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
unsigned int pos0 = 150; // pultsu zabalera 0° posiziorako
unsigned int pos180 = 500; // pultsu zabalera 180° posiziorako
int x = 0;
int y = 0;
int botoia_1 = 2; //botoien sarrerak arduinoan
int botoia_2 = 4;
int botoia_3 = 5;
int botoia_4 = 3;
int botoia_5 = 7; //F Segurtasun botoia
int botoia_6 = 6;
bool balioa_1 = true; //botoia zapaltzean bidaltzen duen informazioa
bool balioa_2 = true;
bool balioa_3 = true;
bool balioa_4 = true;
bool balioa_5 = true;
bool balioa_6 = true;
bool balioa_1_aurrekoa = true;
bool balioa_2_aurrekoa = true;
bool balioa_3_aurrekoa = true;
bool balioa_4_aurrekoa = true;
bool balioa_5_aurrekoa = true;
bool balioa_6_aurrekoa = true;
int i = 1; //aldagai baloreak
int k = 165;//ukondoa
int j = 90; //eskua
int zilindroa = 11;
int angeluaSerbo2=179;
int gehikuntza=5;
int gehikuntzak=5;
int gehikuntzaj=15; // Pausu bakoitzean gehituo=ko diren graduak
bool segurtasunEgoera = true; // 1= Martxan RUN 0=Geratu STOP
bool eskuaEgoera = true;
void setup() {
  Serial.begin(9600);
servos.begin();
servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
pinMode(zilindroa,OUTPUT);
digitalWrite(zilindroa, HIGH);
setServo(1, 96);
setServo(12, angeluaSerbo2);
setServo(13, k);
setServo(14, j);
} 
void setServo(uint8_t n_servo, int angulo) {
int duty;
duty = map(angulo, 0, 180, pos0, pos180);
servos.setPWM(n_servo, 0, duty);
}
void loop() {
balioa_1 = digitalRead(botoia_1);
balioa_2 = digitalRead(botoia_2);
balioa_3 = digitalRead(botoia_3);
balioa_4 = digitalRead(botoia_4);
balioa_5 = digitalRead(botoia_5);
Serial.print("Botoia_1 balioa: ");
Serial.println(balioa_1);
Serial.print("Botoia_2 balioa: ");
Serial.println(balioa_2);
Serial.print("Botoia_3 balioa: ");
Serial.println(balioa_3);
Serial.print("Botoia_4 balioa: ");
Serial.println(balioa_4);
Serial.print("Botoia_5 balioa: ");
Serial.println(balioa_5);
Serial.print("Botoia_6 balioa: ");
Serial.println(balioa_6);
Serial.println(" ");
Serial.println(" ");
//ukondoa
if (balioa_1 == LOW) {
k=k+gehikuntzak;
k=constrain(k,0,180);
setServo(13, k);
} if
(balioa_2 == LOW) {
k=k-gehikuntzak;
k=constrain(k,0,180);
setServo(13, k);
}
//pintza botoi urdinak
if (balioa_3 == LOW) {
j=j+gehikuntzaj;
j=constrain(j,5,170);
setServo(14, j);
} if
(balioa_4 == LOW) {
j=j-gehikuntzaj;
j=constrain(j,5,170);
setServo(14, j);
}
// zilindro pneumatikoa
if (balioa_6 != balioa_6_aurrekoa) {
if (balioa_6 == LOW) {
digitalWrite(zilindroa, LOW);
delay(20);
digitalWrite(zilindroa, HIGH);
Serial.println("ZILINDROA KANPOAN!!!");
}
balioa_6_aurrekoa = balioa_6 ;
} 
if(balioa_5 != balioa_5_aurrekoa) {
if (balioa_5 == LOW) {
segurtasunEgoera =! segurtasunEgoera;
Serial.print("Segurtasun egoera hurengoa da, RUN edo STOP: ");
Serial.print(segurtasunEgoera);
}
balioa_5_aurrekoa = balioa_5 ;
} 
if (segurtasunEgoera == false ){i=10;}
Serial.print("Segurtasun egoera = ");
Serial.println(i);
Serial.println(" ");
x = analogRead(0);
y = analogRead(1);
Serial.print("X balioa: ");
Serial.println(x);
Serial.print("Y balioa: ");
Serial.println(y);
Serial.println(" ");
switch (i) {
case 1:
//-------- 1 SERBOA -- (OINARRIA !!!!) ---------------//----------
if ((x >= 0) && (x <= 454)) {
setServo(1, 89);
Serial.print("Oinarria: ");
Serial.println("ABIADURA -");
} 
else if ((x > 454) && (x <= 570)) {
setServo(1, 96);
Serial.print("Oinarria: ");
Serial.println("ABIADURA 0");
} 
else if ((x > 570) && (x <= 1024)) {
setServo(1, 109);
Serial.print("Oinarria: ");
Serial.println("ABIADURA +");
}
//---------- 2 SERBOA ---------------------------
if ((y >= 0) && (y <= 494)) {
angeluaSerbo2 = angeluaSerbo2 - gehikuntza;
angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
setServo(12, angeluaSerbo2);
Serial.print("Sorbalda: ");
Serial.println(angeluaSerbo2);
} 
else if ((y > 494) && (y <= 530)) {
setServo(12, angeluaSerbo2);
Serial.print("Sorbalda: ");
Serial.println(angeluaSerbo2);
} 
else if ((y > 530) && (y <= 1024)) {
angeluaSerbo2 = angeluaSerbo2 + gehikuntza;
angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
setServo(12, angeluaSerbo2);
Serial.print("Sorbalda: ");
Serial.println(angeluaSerbo2);
}
break;
//-------------- STOP EGOERA GERATU!!!! -------------------//----------
case 10:
setServo(1, 96);
setServo(12, angeluaSerbo2);
setServo(13, k);
setServo(14, j);
if (segurtasunEgoera == true ){i=1;}
break;
//-------------------------------------------------------------//----------
default:
Serial.println("ERROREA: Serbo bikotea ezin aurkitu!!");
break;
} 
Serial.print("Ukondoa: ");
Serial.println(k);
Serial.print("Pintza: ");
Serial.println(j);
delay(0);
//---------------------------------------------//----------
}


