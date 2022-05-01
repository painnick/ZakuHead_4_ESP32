#include "Arduino.h"

class LEDs {
public:
    LEDs(uint8_t red_pin_no, uint8_t orange_pin_no);
    void red(uint16_t bright);
    void orange(uint16_t bright);
private:
    uint8_t RED_PIN, ORANGE_PIN;
};
