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

int rKnobRead;
int lastKnobRead;
int selectedMirror = 0;
// the index of the mirror, from 0 to 5
int UserInterface::getMirrorSelected() {

   int encoderValue = hardware.leftKnob.read();
    int prevMirror = selectedMirror;
    // Calculate the selected mirror based on the encoder value
    selectedMirror = (encoderValue - encoderMirrorZero) % 6;
    
    // Handle the case when it wraps around
    if (selectedMirror < 0) {
        selectedMirror += 6;
    }
    
    // Check for disabled mirrors and skip them
    while (disabledMirrors[selectedMirror]) {
        selectedMirror = (selectedMirror + 1) % 6;
    }
    if (prevMirror != selectedMirror){
        encoderMirrorAngleZero = (hardware.rightKnob.read() - mirrorAngles[selectedMirror]);
    }
    

    return selectedMirror;
}

// degrees
int UserInterface::getMirrorRotation() {
    int rKnobRead = hardware.rightKnob.read();
    
    // Calculate the angle based on the knob and update the selected mirror's angle
    mirrorAngles[selectedMirror] = (rKnobRead - encoderMirrorAngleZero);
    
    // Ensure the angle stays within [-90, 90] degrees
    if (mirrorAngles[selectedMirror] < -90) {
        mirrorAngles[selectedMirror] = -90;
        encoderMirrorAngleZero = (hardware.rightKnob.read() - mirrorAngles[selectedMirror]);
    } else if (mirrorAngles[selectedMirror] > 90) {
        mirrorAngles[selectedMirror] = 90;
        encoderMirrorAngleZero = (hardware.rightKnob.read() - mirrorAngles[selectedMirror]);
    }
    
    return -mirrorAngles[selectedMirror];

}

// of the currently selected mirror, only needed if the position changes
// by some other means in code
void UserInterface::setMirrorAngle(int degrees, int index) {
    // Todo: set the angle of the selected mirror and update encoderMirrorAngleZero as needed

    
    if (selectedMirror == index) // if Selected Mirror changes
    {
        encoderMirrorAngleZero = (hardware.rightKnob.read() + degrees);
    }
    mirrorAngles[index] = -degrees;
        
}

bool UserInterface::isButtonPushed() {
    return hardware.arcadeButton.read();
}

void UserInterface::setWaitingToStart(bool isWaitingToStart) {
    // Todo: update the arcade button as appropriate 
    hardware.arcadeButton.setLED(isWaitingToStart ? 1 : 0); // turn on Arcade Button
}

void UserInterface::setMirrorDisabled(int index, bool isDisabled) { // True indicates Disabled Mirror
    // Todo: update disabledMirrors. Any mirror that is disabled should not be allowed
    //       for selection and it should "skip over" the mirror when reporting which is
    //       selected.

    // Update the disabledMirrors array
    disabledMirrors[index] = isDisabled;
    
    // If the currently selected mirror is disabled, find the next available mirror
    if (index == selectedMirror && isDisabled) {
        for (int i = (selectedMirror + 1) % 6; i != selectedMirror; i = (i + 1) % 6) {
            if (!disabledMirrors[i]) {
                selectedMirror = i;
                break;
            }
        }
    }
}