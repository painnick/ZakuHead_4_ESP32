#include "leds.h"
#include "analogWrite.h"

LEDs::LEDs(uint8_t red_pin_no, uint8_t orange_pin_no)
: RED_PIN(red_pin_no), ORANGE_PIN(orange_pin_no)
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(ORANGE_PIN, OUTPUT);
}

void LEDs::red(uint16_t bright) {
    analogWrite(RED_PIN, bright);
}

void LEDs::orange(uint16_t bright) {
    analogWrite(ORANGE_PIN, bright);
}
