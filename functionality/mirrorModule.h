

#ifndef MIRROR_MODULE_INCLUDED
#define MIRROR_MODULE_INCLUDED

#include "hardware.h"

class MirrorModule {
    public:
    enum Mode {
        DEFAULT,
        DISABLED,
        SELECTED
    };
    private:
    // todo - create attributes of the class like Servo, LEDs, indexOfLed, etc.
    Servo* servo;
    AddressableLEDStrip* leds;
    int LEDIndex;
    Mode mode;
    int angle;


    public:
    MirrorModule(Servo* servo, AddressableLEDStrip* leds, int LEDIndex);

    void setMode(Mode mode);

    Mode getMode();

    void setAngle(int degrees);

    // gets the angle in degrees
    int getAngle();
};

#endif // MIRROR_MODULE_INCLUDED