#include <ESP32Servo.h>

class ZakuServo {
public:
    ZakuServo(uint8_t servo_pin);
    void setup();
    uint32_t left(uint32_t step);
    uint32_t right(uint32_t step);
private:
    Servo* servoN1; // For Camera
    Servo* servoN2; // For Camera
    Servo* servo1;
    uint8_t servo_pin;
    int servo1Pos;
};

