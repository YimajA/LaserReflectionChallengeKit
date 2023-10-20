#include "ledArcadeButton.h"
#include <chrono>

LEDArcadeButton::LEDArcadeButton(PinName inputPin, PinName ledPin): in(inputPin), out(ledPin) {
    this->ledValue = 0;
    this->t.start();
    this->lastRead = this->t.elapsed_time().count();
    // this->in.mode(PullUp); // enable this if no external pullup/pulldown resistor is provided!
}

void LEDArcadeButton::setLED(float value) {
    this->ledValue = value;
    this->lastRead = this->t.elapsed_time().count();

    if (value == 1) {
        this->out.write(1);
    } else {
        this->out.write(0);
    }
}

bool LEDArcadeButton::read() {
    if (this->ledValue > 0 && this->ledValue < 1) {
        uint32_t currUs = this->t.elapsed_time().count();
        uint32_t usOn = this->ledValue * 10000;
        uint32_t cycleAmt = currUs % 10000;
        this->out.write(cycleAmt < usOn);
    }

    return this->in.read();
}