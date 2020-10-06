/*  ----------------------------------------------------------------
 Pausoz pausoko motorra alde batetara 4095 pauso mugitu eta ondoren 
 beste aldera pauso berak mugitzen dituen programa.

 Motorraren kontrola PAUSO ERDIKO KONTOLAREKIN diseinatua dago. 
  by Axpi
  This example code is in the public domain.

  Eskerrak  http://www.prometec.net/motor-28byj-48                                        Prog_4_2
    
  Stepperra: 28BYJ-48 con Arduino
--------------------------------------------------------------------  
*/
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int steps_left=4095;         // Pauso gehiago edo gutxiago definitzeko parametroa
boolean Direction = true;    
int Steps = 0;

// Pauso erdiko Matrizea. Beste kontroletarako matrizea aldatu.

int Paso [ 8 ][ 4 ] =        
    {   {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
        {1, 0, 0, 1}
     };

void setup()
    {
      Serial.begin(115200);
      pinMode(IN1, OUTPUT); 
      pinMode(IN2, OUTPUT); 
      pinMode(IN3, OUTPUT); 
      pinMode(IN4, OUTPUT); 
    }

void loop() 
{     while(steps_left>0)
         {
           stepper() ;     // Pauso bat aurrera
           steps_left-- ;  // Pauso bat gutxiago egin da.
           delay (1) ;
         }
      delay(300);
      Direction=!Direction; // Norantza aldatu
      steps_left=4095;      // Pauso kopurua berrebiarazi
}

void stepper()              //Pauso bat aurrera egiten duen Funtzioa
{
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  SetDirection();

  
  Serial.print("Pausoak:  ");
  Serial.println(steps_left);
  Serial.print("Pausoa:  ");
  Serial.println(Steps);
  Serial.print("Norantza:  ");
  Serial.println(Direction);
  Serial.println("");
  
}

// Norantzaren arabera bobinen eszitazio norantza definitzen duen Funtzioa
void SetDirection()     
{
    if(Direction)
        Steps++;
    else 
        Steps--; 
     
    Steps = ( Steps + 8 ) % 8 ;
}
