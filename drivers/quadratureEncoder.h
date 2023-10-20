

#ifndef QUADRATURE_ENCODER_INCLUDED
#define QUADRATURE_ENCODER_INCLUDED

#undef __ARM_FP
#include "mbed.h"

class QuadratureEncoder {
    private:
    DigitalIn a;
    DigitalIn b;

    int ticks;
    int pos;
    int pos_before;
    int diff;

    int convertGrayToBinary ();

    public:
    QuadratureEncoder(PinName A, PinName B);

    // return how many 'ticks' the encoder has moved so far
    int read();
};

#endif // QUADRATURE_ENCODER_INCLUDED