#undef __ARM_FP
#include "mbed.h"
#include "hardware.h"
#include "userInterface.h"


// main() runs in its own thread in the OS
int main()
{
    
    //initialize the hardware
    _Hardware hardware;

    UserInterface uI1 = 

    // End Setup

    //Yimaj
    while (true) {
        // Start Loop
        
        // Read user input and test the UserInterface functions
        int selectedMirror = UserInterface::getMirrorSelected();
        int mirrorRotation = UserInterface::getMirrorRotation();
        bool buttonPushed = UserInterface::isButtonPushed();

        // Print out the selected mirror and rotation for testing
        printf("Selected Mirror: %d\n", selectedMirror);
        printf("Mirror Rotation: %d degrees\n", mirrorRotation);
        printf("Button Pushed: %s\n", buttonPushed ? "Yes" : "No");
        
        // End Loop
    }
}

