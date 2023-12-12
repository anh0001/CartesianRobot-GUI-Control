#include <Arduino.h>
#include <Ps3Controller.h>
#include <ESP32Encoder.h>
#include <ESP32Servo.h>
#include "motor.h"

// int pos;
bool stop = false;
// Infrared
// #define SENSOR_COUNT 8
// int sensorPins[SENSOR_COUNT] = {34, 35, 32, 33, 25, 23, 22, 1};

// Encoder M1 KANAN
// #define clk_m1 4 //ENC A
// #define dt_m1 8 //ENC B
// // Encoder M2 KIRI
// #define clk_m2 15 // ENC A
// #define dt_m2 2 // ENC B
#define Button1 14
#define ButtonStart 34

// Motor 1
#define en1_motor1 16
#define en2_motor1 17
#define pwm_motor1 23
// Motor 2
#define en1_motor2 18
#define en2_motor2 19
#define pwm_motor2 22
// Servo
#define pinServo1 13
#define pinServo2 12

#define s0 25    
#define s1 33    
#define s2 32    
#define sig 35  

//input driver
#define IN3 16   // IN1
#define IN4 17  // IN2
#define IN1 18  // IN3
#define IN2 19  // IN4

// Object
ESP32Encoder encoderM1;
ESP32Encoder encoderM2;
Servo servo1;
Servo servo2;

// Global Variables
volatile int posM1 = 0;
volatile int posM2 = 0;

// Function Prototypes
void motor(int8_t speed1, int8_t speed2);
void readEnc();

uint16_t In_Sensor[7];
uint8_t Bin_Sensor, Logic_Sensor[7]; 
float Error = 0, Last_Error = 0, I_Error = 0, D_Error = 0;
float Kp, Ki, Kd, u;
int Set_Point = 0, NilaiPosisi, flag_PID;
int PwmL, PwmR, status_PID, Index_Sensor;
char data[70];

unsigned int nilaiMin[8], nilaiMax[8], nilaiRef[8];
uint16_t sensorValue[8];

uint16_t readLine(uint8_t channel){
  if(channel & 0x01) digitalWrite(s0, HIGH); else digitalWrite(s0, LOW);
  if(channel & 0x02) digitalWrite(s1, HIGH); else digitalWrite(s1, LOW);
  if(channel & 0x04) digitalWrite(s2, HIGH); else digitalWrite(s2, LOW);

  return analogRead(sig);
}

void Kalib(){
  for (int i=0; i<8; i++){
     nilaiMin[i] = 5000;
     nilaiMax[i] = 0;
  }
   while(digitalRead(Button1)==LOW){
   for (int i=0; i<8; i++){

    if(readLine(i) > nilaiMax[i]) nilaiMax[i] = readLine(i);
    if(readLine(i) < nilaiMin[i]) nilaiMin[i] = readLine(i);

    nilaiRef[i] = (nilaiMax[i] + nilaiMin[i])/2;
 }
}
}

uint8_t bitSensor(){
  uint8_t bit = 0b00000000;
  
  for(uint8_t i = 0; i < 8; i++){
    sensorValue[i] = readLine(i);
  }

  if (sensorValue[0] > nilaiRef[0]) bit += (0b00000001 << 7);  // Sensor 1
  else                                bit += (0b00000000 << 7);
  if (sensorValue[1] > nilaiRef[1]) bit += (0b00000001 << 6);  // Sensor 2
  else                                bit += (0b00000000 << 6);
  if (sensorValue[2] > nilaiRef[2]) bit += (0b00000001 << 5);  // Sensor 3
  else                                bit += (0b00000000 << 5);
  if (sensorValue[3] > nilaiRef[3]) bit += (0b00000001 << 4);  // Sensor 4
  else                                bit += (0b00000000 << 4);
  if (sensorValue[4] > nilaiRef[4]) bit += (0b00000001 << 3);  // Sensor 5
  else                                bit += (0b00000000 << 3);
  if (sensorValue[5] > nilaiRef[5]) bit += (0b00000001 << 2);  // Sensor 6
  else                                bit += (0b00000000 << 2);
  if (sensorValue[6] > nilaiRef[6]) bit += (0b00000001 << 1);  // Sensor 7
  else                                bit += (0b00000000 << 1);
  if (sensorValue[7] > nilaiRef[7]) bit += (0b00000001 << 0);  // Sensor 8
  else                                bit += (0b00000000 << 0);
  
  return bit;
}


void scan_Sensor(uint16_t speed){
  switch (bitSensor()){
    case 0b00000010: NilaiPosisi = 5;  status_PID = 1; flag_PID = 0; break;
    case 0b00000110: NilaiPosisi = 4;  status_PID = 1; flag_PID = 0; break;
    case 0b00000100: NilaiPosisi = 3;  status_PID = 1; flag_PID = 0; break;
    case 0b00001100: NilaiPosisi = 2;  status_PID = 1; flag_PID = 0; break;
    case 0b00001000: NilaiPosisi = 1;  status_PID = 1; flag_PID = 0; break;
    case 0b00011000: NilaiPosisi = 0;                  flag_PID = 0; break;
    case 0b00010000: NilaiPosisi = -1; status_PID = 0; flag_PID = 0; break;
    case 0b00110000: NilaiPosisi = -2; status_PID = 0; flag_PID = 0; break;
    case 0b00100000: NilaiPosisi = -3; status_PID = 0; flag_PID = 0; break;
    case 0b01100000: NilaiPosisi = -4; status_PID = 0; flag_PID = 0; break;
    case 0b01000000: NilaiPosisi = -5; status_PID = 0; flag_PID = 0; break;
    
    case 0b11110000: NilaiPosisi = 6; status_PID = 0; flag_PID = 0; break;
    case 0b00001111: NilaiPosisi = -6; status_PID = 0; flag_PID = 0; break;
    case 0b01111110: NilaiPosisi = 0;                  flag_PID = 3; break;

    case 0b00000000: 
      if (status_PID == 1)  { flag_PID = 1; }
      else                  { flag_PID = 2; }
      break; 
  }

  if (flag_PID == 0){
    //Error = Set_Point - NilaiPosisi;
    Error = NilaiPosisi - Set_Point;
    D_Error = Error - Last_Error;
    Last_Error = Error;
    u = Kp * Error + Kd * D_Error;
    PwmL = speed - u; PwmR = speed + u;
    PwmL = constrain(PwmL, -speed, speed);
    PwmR = constrain(PwmR, -speed, speed);

    // if(PwmL<0) PwmL=0;
    // if(PwmR<0) PwmR=0;
    
    motor(PwmL, PwmR);
  }
  else if (flag_PID == 1){
    motor(-127, 127);   // Kiri
  }
  else if (flag_PID == 2){
    motor(127, -127);   // Kanan  
  } else if (flag_PID == 3){
    motor(0, 0);   // Kanan  
  }
  void motor(int lpwm, int rpwm) {
  if (lpwm > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else if(lpwm == 0){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }
  else if(lpwm <0){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  }

  if (rpwm > 0) {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if(rpwm == 0){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else if(rpwm<0){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
}
}

void setup() {
  Serial.begin(115200);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(sig, INPUT);

  // Motor
  pinMode(en1_motor1, OUTPUT);
  pinMode(en2_motor1, OUTPUT);
  pinMode(en1_motor2, OUTPUT);
  pinMode(en2_motor2, OUTPUT);
  pinMode(pwm_motor1, OUTPUT);
  pinMode(pwm_motor2, OUTPUT);

  pinMode(Button1, INPUT_PULLUP);

  //Input driver
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  // PWM
  ledcSetup(pwm_motor1, 5000, 8);
  ledcSetup(pwm_motor2, 5000, 8);
  ledcAttachPin(pwm_motor1, pwm_motor1);
  ledcAttachPin(pwm_motor2, pwm_motor2);

  // Servo
  servo1.attach(pinServo1);
  servo1.attach(pinServo2);

  servo1.write(75); // set posisi awal
  servo2.write(90);


  //Button Start
  pinMode(ButtonStart, INPUT_PULLUP);

  // Joystick
  Ps3.begin("24:6f:28:10:67:4a"); // Sesuaikan alamat Bluetooth PS3 Anda
}

void loop() {
  //PID
    if(digitalRead(Button1)==LOW){
    motor(0,0);
    Kalib();
  }

  Kp = 0.2; Kd = 0.8;
  scan_Sensor(400);
  //   for(uint8_t i = 0; i < 8; i++){
  //   sensorValue[i] = readLine(i);
  //   Serial.print(sensorValue[i]);
  //   Serial.print("\t");
  //   Serial.print("\t");
  // }
  // Serial.print(bitSensor(), BIN);
  // Serial.println();

  // Joystick control
  if (Ps3.isConnected()) {
    if (Ps3.data.analog.stick.ly < -1) {
      Serial.println("Maju");
      analogWrite(pwm_motor1, abs(Ps3.data.analog.stick.ly * 2));
      digitalWrite(en1_motor1, HIGH);
      digitalWrite(en2_motor1, LOW);
      analogWrite(pwm_motor2, abs(Ps3.data.analog.stick.ly * 2));
      digitalWrite(en1_motor2, HIGH);
      digitalWrite(en2_motor2, LOW);
    }
    else if (Ps3.data.analog.stick.ly > -1) {
        Serial.println("Mundur");
        analogWrite(pwm_motor1, abs(Ps3.data.analog.stick.ly * 2));
        digitalWrite(en1_motor1, LOW);
        digitalWrite(en2_motor1, HIGH);
        analogWrite(pwm_motor2, abs(Ps3.data.analog.stick.ly * 2));
        digitalWrite(en1_motor2, LOW);
        digitalWrite(en2_motor2, HIGH);
    }
    else if (Ps3.data.analog.stick.rx > -1){
        Serial.println("Belok Kanan");
        analogWrite(pwm_motor1, abs(Ps3.data.analog.stick.rx * 2));
        digitalWrite(en1_motor1, LOW);
        digitalWrite(en2_motor1, HIGH);
        analogWrite(pwm_motor2, abs(Ps3.data.analog.stick.rx * 2));
        digitalWrite(en1_motor2, HIGH);
        digitalWrite(en2_motor2, LOW);
      
     }
    else if (Ps3.data.analog.stick.rx < -1){
        Serial.println("Belok Kiri");
        analogWrite(pwm_motor1, abs(Ps3.data.analog.stick.rx * 2));
        digitalWrite(en1_motor1, HIGH);
        digitalWrite(en2_motor1, LOW);
        analogWrite(pwm_motor2, abs(Ps3.data.analog.stick.rx * 2));
        digitalWrite(en1_motor2, LOW);
        digitalWrite(en2_motor2, HIGH);
    }
    else if (Ps3.event.button_down.circle){

        Serial.println("Persiapan Bola");
        if (!stop) {
          servo1.write(0);
          delay (100);
          stop = true;
        } else {
          servo1.write(75);
          delay(100);
          stop = false;
        }
          // for(pos = 90; pos >= -1; pos+= 1) //untuk perulangan posisi 90 - 0 derajat
          // {
          //   servo1.write(pos);
          //   // servo2.write(pos);
          //   delay(10);
          // }
          // for(pos = 90; pos > 0; pos-= 1) //untuk perulangan posisi 0 - 90 derajat
          // {
          //   servo1.write(pos);
          //   // servo2.write(pos);
          //   delay(10);
          // }
          
        // if(Serial.available()) {
        //   int angle = Serial.parseInt();
        //   servo1.write(angle);
        //   // servo2.write(angle);
        // }
        // delay(20);
    }

    else if (Ps3.data.analog.button.l2){
      Serial.println("Ambil Bola");
      int pos = 90;
      for(pos = 0; pos >= -1; pos-= 1) //untuk perulangan posisi 90 - 0 derajat
            {
              servo2.write(pos);
              // servo2.write(pos);
              delay(10);
            }
    }

    else if (Ps3.data.analog.button.l1) {
      Serial.println("Angkat Bola");
      int pos = 90;
      for(pos = 0; pos <= 90; pos+=1)
      {
        servo2.write(pos);

        delay(10);
      }
    }
    
    else {
        Serial.println("Berhenti");
        analogWrite(pwm_motor1, 0);
        digitalWrite(en1_motor1, LOW);
        digitalWrite(en2_motor1, LOW);
        analogWrite(pwm_motor2, 0);
        digitalWrite(en1_motor2, LOW);
        digitalWrite(en2_motor2, LOW);
    }
  }

}



void readEnc() {
  posM1 = encoderM1.getCount();
  posM2 = encoderM2.getCount();
}