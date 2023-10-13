

#ifndef ADDRESSABLE_LED_INCLUDED
#define ADDRESSABLE_LED_INCLUDED

#undef __ARM_FP
#include "mbed.h"
#include "neostrip.h"

class AddressableLEDStrip {
    private:
    NeoStrip strip;
    int numberOfLEDs;

    public:
    typedef struct {
        char blue;
        char green;
        char red;
        char _unused;
    } Color;

    AddressableLEDStrip(PinName pin, int numberOfLEDs);

    void set(Color* colors, int count);

    void setLED(int index, Color color);
};

#endif // ADDRESSABLE_LED_INCLUDED