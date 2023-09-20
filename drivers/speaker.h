

#ifndef SPEAKER_INCLUDED
#define SPEAKER_INCLUDED

#undef __ARM_FP
#include "mbed.h"
#include "libraries/asyncIO/analogOutAsync.cpp"

class Speaker {
    private:
    AnalogOutAsync* aOut;

    public:
    Speaker(PinName pin);

    void playToneSin(int freqency, int durationMillis);

    void playToneSquare(int frequency, int durationMillis);
};

#endif // SPEAKER_INCLUDED