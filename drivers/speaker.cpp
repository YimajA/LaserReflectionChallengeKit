#include "speaker.h"

Speaker::Speaker(PinName pin) {
    this->aOut = new AnalogOutAsync(pin);
}

void Speaker::playToneSin(int freqency, int durationMillis) {
    // Todo
}

void Speaker::playToneSquare(int frequency, int durationMillis) {
    // Todo
}