#include "userInterface.h"
#include "hardware.h"
//Yimaj Ahmed

// the value from the encoder that corresponds to mirror zero
// this value may change if the user tries to spin the encoder
// around too far, this should shift
// the reference.
int UserInterface::encoderMirrorZero = 0;

// Similar to the above, but for the angles of the mirrors
int UserInterface::encoderMirrorAngleZero = 0;

// Used for when the user switches mirrors, it should be able to
// grab the angle of the mirror the user switches to so that it
// can update the encoderMirrorAngleZero appropriately
int UserInterface::mirrorAngles[6] = {0, 0, 0, 0, 0, 0};

// to know whether to allow selection of a given mirror
bool UserInterface::disabledMirrors[6] = {false, false, false, false, false, false};

// the index of the mirror, from 0 to 5
int UserInterface::getMirrorSelected() {
    // Todo: read from the left encoder and determine which mirror is selected
    hardware.leftKnob.read();
    for (int i = 0; i < 6; i++) {
        if (stateOfMirrors[i] == true) {
            //Only Going through mirrors that are not disabled
            hardware.addressableLEDs.set(); // turn the LED of the mirror on
            //
        }
    }
    return 0;

    for (int j = 0; j < 360; j++) {
        if(disabledMirrors[j] == false) { // skip over disabled mirrors
            continue;
        } else {
            hardware.addressableLEDs.set(white, 1);
        }
    }

}

// degrees
int UserInterface::getMirrorRotation() {
    // Todo: read from the right encoder and determine the angle of the selected mirror
    //Rotary Encoder
    int indexofMirror
    for (loop through the rotation of LeftKnob)
    if (right knob is turned by one tick) {
        mirrorAngles[indexofMirror]++;
        hardware.leftKnob.read(); // int number of ticks negative to positive thousand
    }
    //
    if(hardware.leftKnob.read()) {
        mirrorAngles[i]++;
    }
    
    return 0;
}

// of the currently selected mirror, only needed if the position changes
// by some other means in code
void UserInterface::setMirrorAngle(int degrees, int index) {
    // Todo: set the angle of the selected mirror and update encoderMirrorAngleZero as needed
    mirrorAngles[index] = degrees;
}

bool UserInterface::isButtonPushed() {
    return hardware.arcadeButton.read();
}

void UserInterface::setWaitingToStart(bool isWaitingToStart) {
    // Todo: update the arcade button as appropriate 
    hardware.arcadeButton.setLED(1); // turn on Arcade Button
}

void UserInterface::setMirrorDisabled(int index, bool isDisabled) { // True indicates Disabled Mirror
    // Todo: update disabledMirrors. Any mirror that is disabled should not be allowed
    //       for selection and it should "skip over" the mirror when reporting which is
    //       selected.
    disabledMirrors[index] = true;
}