#include "quadratureEncoder.h"
#include "mbed.h"

int ticks;
int pos; int pos_before;
int diff;
QuadratureEncoder::QuadratureEncoder(PinName A, PinName B): a(A), b(B) {
    // add pullups if necessary
    a.mode(PullUp);
    b.mode(PullUp);
    wait(0.001);
    ticks = 0; pos = 0; diff = 0; pos_before = 0;
}

// this function converts Gray code into a binary number
// 00 -> 0, 01 -> 1, 11 -> 2, 10 -> 3
int QuadratureEncoder::convertGrayToBinary () {
 
    if (a == 0 && b == 0) {
        return 0;
    } else if (a == 0 && b == 1) {
        return 1;
    } else if (a == 1 && b == 1) {
        return 2;
    } else {
        return 3;
    }
    
}

int QuadratureEncoder::read() {

    // read out the current position
    pos = convertGrayToBinary();
        
    // calculate the difference to previous position
    diff = pos_before - pos;

    // turned clockwise
    if (((diff == -1) || (diff == 3))) {
        pos_before = pos;
        ticks++;
        
    // turned counter-clockwise
    } else if (((diff == 1) || (diff == -3))) {
        pos_before = pos;
        ticks--;

    // Update the previous state for the next reading
    pos_before = pos;

    return ticks/4;
}