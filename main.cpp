#undef __ARM_FP
#include "mbed.h"


// main() runs in its own thread in the OS
int main()
{
    
    //initialize the hardware


    // End Setup

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

