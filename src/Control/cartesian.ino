#include <Stepper.h>
#include <Servo.h>

Servo servoZ;

const int stepsPerRevolution = 200;  // ganti ini sesuai jumlah langkah per revolusi untuk motor Anda

Stepper myStepperx(stepsPerRevolution, 2, 5);
Stepper mySteppery(stepsPerRevolution, 3, 6);

int currentPositionX = 0;
int currentPositionY = 0;
bool isZUp = true;

void setup() {
  myStepperx.setSpeed(500);
  mySteppery.setSpeed(500);

  servoZ.attach(9);
  servoZ.write(90);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    switch (command) {
      case 'w':

        myStepperx.step(-stepsPerRevolution);
        currentPositionX -= 1;
        
        break;
      case 's':

        myStepperx.step(stepsPerRevolution);
        currentPositionX += 1;
        
        break;
      case 'a':
        mySteppery.step(stepsPerRevolution);
        currentPositionY += 1;
        
        break;
      case 'd':
        mySteppery.step(-stepsPerRevolution);
        currentPositionY -= 1;
        
        break;
      case 'x':
        moveStepperX();

        break;
      case 'y':
        moveStepperY();
        
        break;
      case 'r':
        currentPositionX = 0;
        currentPositionY = 0;

        break;
      case 'z':
        // servoZ.write(90);
        // isZUp = true;
        servo();

        break;
    }

  }
  Serial.print("X = ");
  Serial.println(currentPositionX);
  Serial.print("Y = ");
  Serial.println(currentPositionY);
  Serial.print("Z = ");
  Serial.println(isZUp ? "Up" : "Down");
  delay(100);
}



void moveStepperX() {
  while (!Serial.available()) {
    // Tunggu input pengguna
  }

  int numRevolutionsX = Serial.parseInt();

  int stepsX = numRevolutionsX * stepsPerRevolution;

  for (int i = 0; i < abs(stepsX); i+=stepsPerRevolution) {
  myStepperx.step(stepsX);
  //    myStepperx.step(stepsX > 0 ? 1 : -1);
      currentPositionX += (stepsX > 0 ? 1 : -1);

      // Print each step
      Serial.print("X = ");
      Serial.println(currentPositionX);

      delay(10); // Optional delay between steps
    }

  // currentPositionX += stepsX;

}

void moveStepperY() {

  while (!Serial.available()) {
    // Tunggu input pengguna
  }

  int numRevolutionsY = Serial.parseInt();

  int stepsY = numRevolutionsY * stepsPerRevolution;

  for (int i = 0; i < abs(stepsY); i+=stepsPerRevolution) {
  mySteppery.step(stepsY);
  //    mySteppery.step(stepsY > 0 ? 1 : -1);
      currentPositionY += (stepsY > 0 ? 1 : -1);

      // Print each step
      Serial.print("Y = ");
      Serial.println(currentPositionY);

      delay(10); // Optional delay between steps
    }
  // currentPositionY += stepsY;

}

void servo(){
  while (!Serial.available()) {
    // Tunggu input pengguna
  }

  char condition = Serial.read();

  if(condition == '+'){
    servoZ.write(90);
    isZUp = true;
  }
  else if(condition == '-'){
    servoZ.write(0);
    isZUp = false;
  }

  while (Serial.available()) {
    Serial.read();
  }
}