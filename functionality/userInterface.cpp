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

int selectedMirror = 0;
int lastKnobRead;

// the index of the mirror, from 0 to 5
int UserInterface::getMirrorSelected() {
    // Todo: read from the left encoder and determine which mirror is selected
    /*
    int originalRead = hardware.leftKnob.read();
    for (int i = originalRead; i < originalRead + 6; i++) {
        if(disabledMirrors[i] == false) { // skip over disabled mirrors
            continue;
        } else {
           // hardware.addressableLEDs.set(white, i); // 255 255 255
        }
        return i;
    }
    return i;
    */
   for (int i = selectedMirror; i < selectedMirror + 6; i++) {
            if (!disabledMirrors[i % 6]) {
                return i % 6;
                
            }
        }
        // All mirrors are disabled; return a default value or handle the situation
        return -1;
}

// degrees
int UserInterface::getMirrorRotation() {
    // Todo: read from the right encoder and determine the angle of the selected mirror
    //Rotary Encoder
    /*
   int rKnobRead = hardware.rightKnob.read(); // .read returns the number of ticks ranging from -1000 -> +1000
   int currIdx = 0;
   for (int i = currIdx; i < 6; i++) { //Loop through all each Mirror Index
        if (rKnobRead == rKnobRead + 1) { // if the Knob was turned
            mirrorAngles[currIdx]++; // Increase the angle of the selected mirror by 1
        }
   }
   
   return mirrorAngles[currIdx]; // return the angle of the Mirror
   */
    int rKnobRead = hardware.rightKnob.read();
        mirrorAngles[selectedMirror] += rKnobRead - lastKnobRead;
        lastKnobRead = rKnobRead;
        
        // Ensure the angle stays within [0, 180] degrees
        mirrorAngles[selectedMirror] = std::max(0, std::min(180, mirrorAngles[selectedMirror]));

        return mirrorAngles[selectedMirror];

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