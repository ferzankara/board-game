#include <Stepper.h>

// Motor Y (2. Motor) Pin Definitions
#define motorSteps_Y 200
#define motorPin1_Y 6    // Pul/dır pini (D6)
#define motorPin2_Y 3    // Yön pini (D7)

// Motor X (1. Motor) Pin Definitions
#define motorSteps_X 200
#define motorPin1_X 5    // Pul/dır pini (D2)
#define motorPin2_X 2    // Yön pini (D3)

#define buttonPinClockwise_X A0
#define buttonPinCounterClockwise_X A1
#define buttonPinA2_X 9
#define buttonPinA3_X 10

#define buttonPinClockwise_Y A2
#define buttonPinCounterClockwise_Y A3
#define buttonPinA2_Y 11
#define buttonPinA3_Y 12

bool clockwisePressed_X = false;
bool counterClockwisePressed_X = false;
bool clockwisePressed_Y = false;
bool counterClockwisePressed_Y = false;

Stepper stepper_X(motorSteps_X, motorPin1_X, motorPin2_X);
Stepper stepper_Y(motorSteps_Y, motorPin1_Y, motorPin2_Y);

void setup() {
  Serial.begin(9600);
  stepper_X.setSpeed(300);
  stepper_Y.setSpeed(300);
  
  pinMode(buttonPinClockwise_X, INPUT_PULLUP);
  pinMode(buttonPinCounterClockwise_X, INPUT_PULLUP);
  pinMode(buttonPinA2_X, INPUT_PULLUP);
  pinMode(buttonPinA3_X, INPUT_PULLUP);
  
  pinMode(buttonPinClockwise_Y, INPUT_PULLUP);
  pinMode(buttonPinCounterClockwise_Y, INPUT_PULLUP);
  pinMode(buttonPinA2_Y, INPUT_PULLUP);
  pinMode(buttonPinA3_Y, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPinA2_X) == LOW) {
    clockwisePressed_X = false;
  }

  if (digitalRead(buttonPinA3_X) == LOW) {
    counterClockwisePressed_X = false;
  }

  if (digitalRead(buttonPinClockwise_X) == LOW && !clockwisePressed_X) {
    counterClockwisePressed_X = false;
    clockwisePressed_X = true;
    stepper_X.step(1);
  }

  if (digitalRead(buttonPinCounterClockwise_X) == LOW && !counterClockwisePressed_X) {
    clockwisePressed_X = false;
    counterClockwisePressed_X = true;
    stepper_X.step(-1);
  }

  if (digitalRead(buttonPinA2_Y) == LOW) {
    clockwisePressed_Y = false;
  }

  if (digitalRead(buttonPinA3_Y) == LOW) {
    counterClockwisePressed_Y = false;
  }

  if (digitalRead(buttonPinClockwise_Y) == LOW && !clockwisePressed_Y) {
    counterClockwisePressed_Y = false;
    clockwisePressed_Y = true;
    stepper_Y.step(1);
  }

  if (digitalRead(buttonPinCounterClockwise_Y) == LOW && !counterClockwisePressed_Y) {
    clockwisePressed_Y = false;
    counterClockwisePressed_Y = true;
    stepper_Y.step(-1);
  }
}
