#include "addressableLED.h"

AddressableLEDStrip::AddressableLEDStrip(PinName pin, int numberOfLEDs): dout(pin) {
    this->numberOfLEDs = numberOfLEDs;
    this->dout.write(1); // LED control wire is active low, so set the line to HIGH when not in use.
}

void AddressableLEDStrip::set(Color* colors, int count) {
    // Todo
}