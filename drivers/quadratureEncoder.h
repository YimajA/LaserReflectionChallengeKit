

#ifndef QUADRATURE_ENCODER_INCLUDED
#define QUADRATURE_ENCODER_INCLUDED

#undef __ARM_FP
#include "mbed.h"

class QuadratureEncoder {
    private:
    DigitalIn a;
    DigitalIn b;

    public:
    QuadratureEncoder(PinName A, PinName B);

    int read();
};

#endif // QUADRATURE_ENCODER_INCLUDED