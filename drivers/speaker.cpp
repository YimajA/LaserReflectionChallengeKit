#include "speaker.h"

Speaker::Speaker(PinName pin) {
    this->aOut = new AnalogOutAsync(pin);
}

void Speaker::playToneSin(int frequency, int durationMillis) {
    // computing a sin wave of 50 samples
    uint16_t buf[50];
    for (int i = 0; 50 > i; i++) {
        float p = sin((float)i / 25.0f * 3.1415f);
        buf[i] = 0x7FFE * p + 0x8000;
    }

    int timesToRepeat = durationMillis * 1000 / (1000000 / frequency);
    for (int i = 0; timesToRepeat > i; i++) {
        this->aOut->write_u16(buf, 100, frequency * 50);

        while (!this->aOut->isFinished()) {
            // busy wait
        }
    }
}

void Speaker::playToneSquare(int frequency, int durationMillis) {
    // computing a square wave of 2 samples
    uint16_t buf[2];
    buf[0] = 0;
    buf[1] = 0xFFFF;

    int timesToRepeat = durationMillis * 1000 / (1000000 / frequency);
    for (int i = 0; timesToRepeat > i; i++) {
        this->aOut->write_u16(buf, 4, frequency * 2);

        while (!this->aOut->isFinished()) {
            // busy wait
        }
    }
}