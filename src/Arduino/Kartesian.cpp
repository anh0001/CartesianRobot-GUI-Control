#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepperx(stepsPerRevolution, 2, 5);
Stepper mySteppery(stepsPerRevolution, 3, 6);
int speedX = 500;
int speedY = 500;
int currentPositionX = 0;
int currentPositionY = 0;

void setup() {
  myStepperx.setSpeed(500);
  mySteppery.setSpeed(500);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'w':
        moveStepperX(stepsPerRevolution);
        break;
      case 's':
        moveStepperX(-stepsPerRevolution);
        break;
      case 'a':
        moveStepperY(stepsPerRevolution);
        break;
      case 'd':
        moveStepperY(-stepsPerRevolution);
        break;
      case 'x':
        moveStepperX();
        break;
      case 'y':
        moveStepperY();
        break;
      case 'r':
        resetPosition();
        break;
      case 't':
        startMovement();
        break;
      case 'u':
        stopMovement();
        break;
      case 'z':
        displayCoordinates();
        break;
    }
  }

  Serial.print("X = ");
  Serial.println(currentPositionX);
  Serial.print("Y = ");
  Serial.println(currentPositionY);
  delay(100);
}

void moveStepperX(int steps) {
  myStepperx.step(steps);
  currentPositionX += (steps > 0 ? 1 : -1);
}

void moveStepperY(int steps) {
  mySteppery.step(steps);
  currentPositionY += (steps > 0 ? 1 : -1);
}

void moveStepperX() {
  while (!Serial.available()) {
    // Wait for user input
  }

  int numRevolutionsX = Serial.parseInt();
  int stepsX = numRevolutionsX * stepsPerRevolution;

  for (int i = 0; i < abs(stepsX); i += stepsPerRevolution) {
    moveStepperX(stepsX);
    Serial.print("X = ");
    Serial.println(currentPositionX);
    delay(10);
  }
}

void moveStepperY() {
  while (!Serial.available()) {
    // Wait for user input
  }

  int numRevolutionsY = Serial.parseInt();
  int stepsY = numRevolutionsY * stepsPerRevolution;

  for (int i = 0; i < abs(stepsY); i += stepsPerRevolution) {
    moveStepperY(stepsY);
    Serial.print("Y = ");
    Serial.println(currentPositionY);
    delay(10);
  }
}

void resetPosition() {
  currentPositionX = 0;
  currentPositionY = 0;
}

void startMovement() {
  myStepperx.setSpeed(speedX);
  mySteppery.setSpeed(speedY);
  // Mulai pergerakan motor
  myStepperx.step(1); // Langkah kecil untuk memastikan motor aktif
  mySteppery.step(1);
}

void stopMovement() {
  // Memberhentikan pergerakan motor
  myStepperx.setSpeed(0);
  myStepperx.step(0);
  
  mySteppery.setSpeed(0);
  mySteppery.step(0);
}

// Other functions remain unchanged


void displayCoordinates() {
  // Ambil nilai X dan Y dari input Serial
  float x = Serial.parseFloat();
  float y = Serial.parseFloat();

  // Tampilkan koordinat ke Serial Monitor
  Serial.print("Received Coordinates: X=");
  Serial.print(x);
  Serial.print(", Y=");
  Serial.println(y);
   Serial.print("Result: ");
  Serial.print(x + y);
  Serial.println();
}