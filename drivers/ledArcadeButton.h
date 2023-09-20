

#ifndef LED_ARCADE_BUTTON_INCLUDED
#define LED_ARCADE_BUTTON_INCLUDED

#undef __ARM_FP
#include "mbed.h"

class LEDArcadeButton {
    private:
    DigitalIn in;
    DigitalOut out;
    uint32_t lastRead;
    float ledValue;
    Timer t;

    public:
    LEDArcadeButton(PinName inputPin, PinName ledPin);

    void setLED(float value);

    // reads the LED and also updates the LED value if set to a number that isn't 0 or 1.
    bool read();
};

#endif // LED_ARCADE_BUTTON_INCLUDED