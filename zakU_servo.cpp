#include "zaku_servo.h"

ZakuServo zakuServo = ZakuServo(SERVO_PIN);

ZakuServo::ZakuServo(uint8_t servo_pin) : servo_pin(servo_pin), servo1Pos(90) {
  servoN1 = new Servo();
  servoN2 = new Servo();
  servo1 = new Servo();
}

void ZakuServo::setup() {
  servo1->setPeriodHertz(50);    // standard 50 hz servo
  servoN1->attach(2, 1000, 2000);
  servoN2->attach(16, 1000, 2000);
  
  servo1->attach(servo_pin, 1000, 2000);
  
  servo1->write(servo1Pos);
}

int ZakuServo::angle() {
  return servo1Pos;
}

int ZakuServo::left(int step) {
  servo1Pos = min(servo1Pos + step, MONO_EYE_MAX_ANGLE);
  servo1->write(servo1Pos);
  return servo1Pos;
}

int ZakuServo::right(int step) {
  servo1Pos = max(servo1Pos - step, MONO_EYE_MIN_ANGLE);
  servo1->write(servo1Pos);
  return servo1Pos;
}

int ZakuServo::set(int angle) {
  servo1Pos = min(max(angle, MONO_EYE_MIN_ANGLE), MONO_EYE_MAX_ANGLE);
  servo1->write(servo1Pos);
  return servo1Pos;
}
