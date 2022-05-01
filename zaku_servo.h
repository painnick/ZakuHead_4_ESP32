#ifndef ZAKU_SERVO_h
#define ZAKU_SERVO_h

#include <ESP32Servo.h>

class ZakuServo {
public:
    ZakuServo(uint8_t servo_pin);
    void setup();
    int left(int step);
    int right(int step);
private:
    Servo* servoN1; // For Camera
    Servo* servoN2; // For Camera
    Servo* servo1;
    uint8_t servo_pin;
    int servo1Pos;
};

#define SERVO_PIN      14
extern ZakuServo zakuServo;

#endif /* ZAKU_SERVO_h */
