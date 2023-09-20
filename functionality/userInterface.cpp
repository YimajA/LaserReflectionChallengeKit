#include "userInterface.h"
#include "hardware.h"

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

    return 0;
}

// degrees
int UserInterface::getMirrorRotation() {
    // Todo: read from the right encoder and determine the angle of the selected mirror

    return 0;
}

// of the currently selected mirror, only needed if the position changes
// by some other means in code
void UserInterface::setMirrorAngle(int degrees) {
    // Todo: set the angle of the selected mirror and update encoderMirrorAngleZero as needed
}

bool UserInterface::isButtonPushed() {
    // This was done for you as an example of how to interface with the hardware
    return hardware.arcadeButton.read();
}

void UserInterface::setWaitingToStart(bool isWaitingToStart) {
    // Todo: update the arcade button as appropriate
}

void UserInterface::setMirrorDisabled(int index, bool isDisabled) {
    // Todo: update disabledMirrors. Any mirror that is disabled should not be allowed
    //       for selection and it should "skip over" the mirror when reporting which is
    //       selected.
}