// command pins for stepper motor windings (A+, A-, B+, B-)
#define ApPin 9
#define AnPin 10
#define BpPin 11
#define BnPin 12

char stepperPhase = 0; // memorize which stepper motor coil to supply

void setup() {
  pinMode(ApPin, OUTPUT);
  pinMode(AnPin, OUTPUT);
  pinMode(BpPin, OUTPUT);
  pinMode(BnPin, OUTPUT);

}
void loop() {
  delay(2500);
  // update the stepping phase
  stepperPhase = stepperPhase + 1;
  if (stepperPhase > 3) stepperPhase = 0;
  // command the stepper motor coils accordingly
  switch (stepperPhase) {
  case 0: {
    digitalWrite(BnPin, LOW);
    digitalWrite(ApPin, HIGH);
  }
  break;
  case 1: {
    digitalWrite(ApPin, LOW);
    digitalWrite(BpPin, HIGH);
  }
  break;
  case 2: {
    digitalWrite(BpPin, LOW);
    digitalWrite(AnPin, HIGH);
  }
  break;
  case 3: {
    digitalWrite(AnPin, LOW);
    digitalWrite(BnPin, HIGH);
  }
  break;
  } // switch
} //loop()
