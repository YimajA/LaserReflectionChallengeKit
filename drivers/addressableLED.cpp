#include "addressableLED.h"

AddressableLEDStrip::AddressableLEDStrip(PinName pin, int numberOfLEDs): strip(pin, numberOfLEDs) {
    this->numberOfLEDs = numberOfLEDs;
    this->strip.setBrightness(1);
    this->strip.clear();
}

void AddressableLEDStrip::set(Color* colors, int count) {
    this->strip.setPixels(0, count, (const int *)colors);
    this->strip.write();
}

void AddressableLEDStrip::setLED(int index, Color color) {
    this->strip.setPixel(index, *(const int*)(&color));
    this->strip.write();
}