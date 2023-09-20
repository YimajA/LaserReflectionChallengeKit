

#ifndef ADDRESSABLE_LED_INCLUDED
#define ADDRESSABLE_LED_INCLUDED

#undef __ARM_FP
#include "mbed.h"

class AddressableLEDStrip {
    private:
    DigitalOut dout;
    int numberOfLEDs;

    public:
    typedef struct {
        char red;
        char green;
        char blue;
    } Color;

    AddressableLEDStrip(PinName pin, int numberOfLEDs);

    void set(Color* colors, int count);
};

#endif // ADDRESSABLE_LED_INCLUDED