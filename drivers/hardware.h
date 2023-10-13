

#ifndef HARDWARE_INCLUDED
#define HARDWARE_INCLUDED

#include "addressableLED.h"
#include "ledArcadeButton.h"
#include "speaker.h"
#include "Servo.h"
#include "quadratureEncoder.h"

#undef __ARM_FP
#include "mbed.h"

class _Hardware {
    // you should not invoke this class directly, use the global variable 'hardware'
    public:
    AddressableLEDStrip addressableLEDs;
    LEDArcadeButton arcadeButton;
    Speaker speaker;
    Servo servos[6];
    DigitalOut laser;
    AnalogIn lightSensor;
    QuadratureEncoder leftKnob;
    QuadratureEncoder rightKnob;

    inline _Hardware(): addressableLEDs(p17, 6), 
                arcadeButton(p11, p12), 
                speaker(p18),
                laser(p14),
                leftKnob(p6, p5),
                rightKnob(p10, p9),
                lightSensor(p20),
                servos{Servo(p21), Servo(p22), Servo(p23), Servo(p24), Servo(p25), Servo(p26)} {
        servos[0].calibrate(0.001, 90);
        servos[1].calibrate(0.001, 90);
        servos[2].calibrate(0.001, 90);
        servos[3].calibrate(0.001, 90);
        servos[4].calibrate(0.001, 90);
        servos[5].calibrate(0.001, 90);
    } // TODO: update pins!!
};

extern _Hardware hardware;

#endif // HARDWARE_INCLUDED