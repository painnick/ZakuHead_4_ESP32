#include "zaku_servo.h"

ZakuServo::ZakuServo(uint8_t servo_pin) : servo_pin(servo_pin), servo1Pos(90) {
    servoN1 = new Servo();
    servoN2 = new Servo();
    servo1 = new Servo();
}

void ZakuServo::setup() {
  servo1->setPeriodHertz(50);    // standard 50 hz servo
  servoN1->attach(2, 1000, 2000);
  servoN2->attach(13, 1000, 2000);
  
  servo1->attach(servo_pin, 1000, 2000);
  
  servo1->write(servo1Pos);
}

uint32_t ZakuServo::left(uint32_t step) {
    if(servo1Pos <= 170) {
        servo1Pos += step;
        servo1->write(servo1Pos);
    }
    return servo1Pos;
}

uint32_t ZakuServo::right(uint32_t step) {
    if(servo1Pos >= 10) {
      servo1Pos -= step;
      servo1->write(servo1Pos);
    }
    return servo1Pos;
}
