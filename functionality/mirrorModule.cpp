#include "mirrorModule.h"

MirrorModule::MirrorModule(Servo* servo, AddressableLEDStrip* leds, int LEDIndex) {
    // Initialize attributes
    this->servo = servo;
    this->leds = leds;
    this->LEDIndex = LEDIndex;
    this->mode = Mode::DEFAULT; // Set the default mode when the mirror is created.
    this->angle = 0; // Initialize angle to 0 degrees.
}

void MirrorModule::setMode(Mode mode) {
    this->mode = mode;
    if (mode == DEFAULT) {
        leds->setLED(LEDIndex, {0, 0, 0});
    } else if(mode == DISABLED) {
        leds->setLED(LEDIndex, {0, 0, 255});
    } else if(mode == SELECTED) {
        leds->setLED(LEDIndex, {0, 255, 0});
    }
}

MirrorModule::Mode MirrorModule::getMode() {
    return this->mode;
}

void MirrorModule::setAngle(int degrees) {
    // Ensure that degrees stay within the -90->90 range
    degrees = std::max(-90, std::min(90, degrees));
    this->angle = degrees;
    this->servo->write((((float)degrees)/180) + 0.5);
}

// gets the angle in degrees
int MirrorModule::getAngle() {
    return this->angle;
}
