// This code is for DC Motor controlled by L298N or L293D Motor Driver.
// Wiring Details
// ENA : 9 , IN1 : 8 & IN2 : 7
// This code is only for speed control, Please refer separate code available for direction control.
// OUT1 & OUT2 : Motor 1
// This code is only applicable for one motor, If needed please add code for second motor at your end.
// Modified by Axpi 2020

// Motor 1 Pins initialization
int ENA = 9;
int IN1 = 8;
int IN2 = 7;

void setup() {
  
  // Configuring Pins as outputs
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Putting motors in off mode in starting
  Serial.println("");
  speedControl(255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
}

void loop() {
  aurrera();
  delay(1000);
  atzera();
  delay(1000);
  stop();
  delay(1000);
}

void aurrera() {
  // Run forward
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   Serial.println("Aurrerantz");
}

void atzera() {
  // Run backwards
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   Serial.println("Atzerantz");
}

void stop() {
  // Run backwards
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, LOW);
   Serial.println("Stop");
  Serial.println("");
}

void speedControl(int abiadura) {
  // Adjust motor speed as in maximum
   analogWrite(ENA,abiadura);
   delay(250);
   Serial.print("Abiadura: ");
   Serial.println(abiadura);
}
