#include "addressableLED.h"

AddressableLEDStrip::AddressableLEDStrip(PinName pin, int numberOfLEDs): dout(pin) {
    this->numberOfLEDs = numberOfLEDs;
    this->dout.write(1); // LED control wire is active low, so set the line to HIGH when not in use.
}

void AddressableLEDStrip::writeByte(char byte) {
    for (int i = 0; 8 > i; i++) {
        char bit = (byte >> (7 - i)) & 0x1;
        this->writeBit(bit);
    }
}

void AddressableLEDStrip::writeBit(char bit) {
    if (bit) {
        wait_ns(850); // always a 1 before, so no need to re-write it.
        this->dout.write(0);
        wait_ns(400);
        this->dout.write(1);
    } else {
        wait_ns(400);
        this->dout.write(0);
        wait_ns(850);
        this->dout.write(1);
    }
}

void AddressableLEDStrip::set(Color* colors, int count) {
    // reset signal
    this->dout.write(0);
    wait_us(60); // must wait at least 50us
    this->dout.write(1);

    // send the LEDs in order, G, then R, then B
    for (int i = 0; this->numberOfLEDs > i && i < count; i++) {
        this->writeByte(colors[i].green);
        this->writeByte(colors[i].red);
        this->writeByte(colors[i].blue);
    }
}