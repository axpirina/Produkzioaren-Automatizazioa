/* Serboak kontrolatzeko programa.
    Serbo Shield-a erabiliaz
    2018ko Abenduak 09an by Axpi
    
    Kode hau Creatives Commons lizentziapena argitaratzen da.
*/
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0 = 150; // pultsu zabalera 0° posiziorako
unsigned int pos180 = 500; // pultsu zabalera 180° posiziorako
int x = 0;
int y = 0;
int botoia_1 = 2;
int botoia_2 = 4;
int botoia_3 = 5;
int botoia_4 = 3;
int botoia_5 = 7;
bool balioa_1 = true;
bool balioa_2 = true;
bool balioa_3 = true;
bool balioa_4 = true;
bool balioa_5 = true;
bool balioa_1_aurrekoa = true;
bool balioa_2_aurrekoa = true;
bool balioa_3_aurrekoa = true;
bool balioa_4_aurrekoa = true;
bool balioa_5_aurrekoa = true;
int i = 1;
int zilindroa = 11;
int angeluaSerbo2=90;
int angeluaSerbo3=90;
int angeluaSerbo4=90;
int gehikuntza=5;            //  Pausu bakoitzean gehituo=ko diren graduak
bool segurtasunEgoera = true;     //  1= Martxan RUN     0=Geratu  STOP
bool eskuaEgoera = true;

void setup() {
  Serial.begin(9600);
  servos.begin();
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  pinMode(zilindroa,OUTPUT);
  digitalWrite(zilindroa, HIGH);
  setServo(2, angeluaSerbo2);
  setServo(3, angeluaSerbo3);
  setServo(4, angeluaSerbo4);
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
  Serial.print("Botoia_1 balioa:   ");
  Serial.println(balioa_1);
  Serial.print("Botoia_2 balioa:   ");
  Serial.println(balioa_2);
  Serial.print("Botoia_3 balioa:   ");
  Serial.println(balioa_3);
  Serial.print("Botoia_4 balioa:   ");
  Serial.println(balioa_4);
  Serial.print("Botoia_5 balioa:   ");
  Serial.println(balioa_5);
  Serial.println(" ");
  Serial.println(" ");

  if (balioa_1 != balioa_1_aurrekoa) {  //Pultsatu dugunaren seinale
    if (balioa_1 == LOW) {
      Serial.println("HAU DA IKUSI NAHI DUDANA");
      i++;
      if (i == 3) {
        i = 1;
      }
    }
    balioa_1_aurrekoa = balioa_1 ;
  }

  if (balioa_2 != balioa_2_aurrekoa) {
    if (balioa_2 == LOW) {
      i--;
      if (i == 0) {
        i = 2;
      }
    }
    balioa_2_aurrekoa = balioa_2 ;
  }

  if (balioa_3 != balioa_3_aurrekoa) {
    if (balioa_3 == LOW) {
      digitalWrite(zilindroa, LOW);
      delay(20);
      digitalWrite(zilindroa, HIGH);
      Serial.println("ZILINDROA KANPOAN!!!");
    }
    balioa_3_aurrekoa = balioa_3 ;
  }

  if (balioa_5 != balioa_5_aurrekoa) {
    if (balioa_5 == LOW) {
      segurtasunEgoera =! segurtasunEgoera;
      Serial.print("Segurtasun egoera hurengoa da, RUN edo STOP:         ");
      Serial.print(segurtasunEgoera);
    }
    balioa_5_aurrekoa = balioa_5 ;
  }

  if (segurtasunEgoera == false ){i=10;}
  
  Serial.print("Hau da serbo bikotea aukeratzeko i balioa =       ");
  Serial.println(i);
  Serial.println(" ");

  x = analogRead(0);
  y = analogRead(1);

  Serial.print("X balioa:   ");
  Serial.println(x);
  Serial.print("Y balioa:   ");
  Serial.println(y);

  Serial.println(" ");

  switch (i) {
    case 1:
      //-------- 1 SERBOA -- (OINARRIA !!!!) ---------------//----------
      if ((x >= 0) && (x <= 494)) {
        setServo(1, 80);
        Serial.print("Oinarria:    ");
        Serial.println("ABIADURA -");
      }

      else if ((x > 494) && (x <= 530)) {
        setServo(1, 90);
        Serial.print("Oinarria:    ");
        Serial.println("ABIADURA 0");
      }

      else if ((x > 530) && (x <= 1024)) {
        setServo(1, 100);
        Serial.print("Oinarria:    ");
        Serial.println("ABIADURA +");
      }
      //---------- 2 SERBOA ---------------------------
      if ((y >= 0) && (y <= 494)) {
        angeluaSerbo2 = angeluaSerbo2 - gehikuntza;
        angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
        setServo(2, angeluaSerbo2);
        Serial.print("Sorbalda:    ");
        Serial.println(angeluaSerbo2);
      }

      else if ((y > 494) && (y <= 530)) {
        setServo(2, angeluaSerbo2);
        Serial.print("Sorbalda:    ");
        Serial.println(angeluaSerbo2);
      }

      else if ((y > 530) && (y <= 1024)) {
        angeluaSerbo2 = angeluaSerbo2 + gehikuntza;
        angeluaSerbo2 = constrain(angeluaSerbo2, 1, 179);
        setServo(2, angeluaSerbo2);
        Serial.print("Sorbalda:    ");
        Serial.println(angeluaSerbo2);
      }
      break;

    case 2:
      //---------- 3 SERBOA -------------------------//----------
      if ((x >= 0) && (x <= 494)) {
        angeluaSerbo3 = angeluaSerbo3 - gehikuntza;
        angeluaSerbo3 = constrain(angeluaSerbo3, 1, 179);
        setServo(3, angeluaSerbo3);
        Serial.print("Ukalondoa:    ");
        Serial.println(angeluaSerbo3);
      }

      else if ((x > 494) && (x <= 530)) {
        setServo(3, angeluaSerbo3);
        Serial.print("Ukalondoa:    ");
        Serial.println(angeluaSerbo3);
      }

      else if ((x > 530) && (x <= 1024)) {
        angeluaSerbo3 = angeluaSerbo3 + gehikuntza;
        angeluaSerbo3 = constrain(angeluaSerbo3, 1, 179);
        setServo(3, angeluaSerbo3);
        Serial.print("Ukalondoa:    ");
        Serial.println(angeluaSerbo3);
      }
      //------------ 4 SERBOA -------------------------
      if ((y >= 0) && (y <= 494)) {
        angeluaSerbo4 = angeluaSerbo4 - gehikuntza;
        angeluaSerbo4 = constrain(angeluaSerbo4, 1, 179);
        setServo(4, angeluaSerbo4);
        Serial.print("Pintzak:    ");
        Serial.println(angeluaSerbo4);
      }

      else if ((y > 494) && (y <= 530)) {
        setServo(4, angeluaSerbo4);
        Serial.print("Pintzak:    ");
        Serial.println(angeluaSerbo4);
      }

      else if ((y > 530) && (y <= 1024)) {
        angeluaSerbo4 = angeluaSerbo4 + gehikuntza;
        angeluaSerbo4 = constrain(angeluaSerbo4, 1, 179);
        setServo(4, angeluaSerbo4);
        Serial.print("Pintzak:    ");
        Serial.println(angeluaSerbo4);
      }
      break;

   
    //-------------- STOP EGOERA GERATU!!!!  -------------------//----------
      case 10:
        setServo(1, 90);
        setServo(2, 90);
        setServo(3, 90);
        setServo(4, 90);
        if (segurtasunEgoera == true ){i=1;}
      break;
   //-------------------------------------------------------------//----------    
    default:
      Serial.println("ERROREA: Serbo bikotea ezin aurkitu!!");
      break;
  }
  delay(0);
  //---------------------------------------------//----------
}
