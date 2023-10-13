#include "mirrorModule.h"

MirrorModule::MirrorModule(Servo* servo, AddressableLEDStrip* leds, int LEDIndex) {
    // Initialize attributes
    this->servo = servo;
    this->leds = leds;
    this->LEDIndex = LEDIndex;
    this->mode = Mode::DEFAULT; // Set the default mode when the mirror is created.
    this->angle = 0; // Initialize angle to 0 degrees.
    this->updateLED(); // Initialize LED to reflect the default mode.
}

void MirrorModule::setMode(Mode mode) {
    // Todo
    this->mode = mode;
    this->updateLED(); // Update the LED to reflect the new mode.
}

MirrorModule::Mode MirrorModule::getMode() {
    // Todo
    return this->mode;
}

void MirrorModule::setAngle(int degrees) {
    // Ensure that degrees stay within the 0-180 range
    degrees = std::max(0, std::min(180, degrees));
    this->angle = degrees;
}

// gets the angle in degrees
int MirrorModule::getAngle() {
    // Todo
    return this->angle;
}
