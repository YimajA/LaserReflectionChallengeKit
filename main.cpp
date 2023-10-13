#undef __ARM_FP
#include "mbed.h"
#include "hardware.h"
#include "userInterface.h"
#include "mirrorModule.h"


// main() runs in its own thread in the OS
int main()
{
    
    //initialize the hardware
    MirrorModule mirrors[6] = {MirrorModule(&hardware.servos[0], &hardware.addressableLEDs, 0),
                               MirrorModule(&hardware.servos[1], &hardware.addressableLEDs, 1),
                               MirrorModule(&hardware.servos[2], &hardware.addressableLEDs, 2),
                               MirrorModule(&hardware.servos[3], &hardware.addressableLEDs, 3),
                               MirrorModule(&hardware.servos[4], &hardware.addressableLEDs, 4),
                               MirrorModule(&hardware.servos[5], &hardware.addressableLEDs, 5),
    }; 


     UserInterface uI1;

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
        wait_us(1000000);
        
        // End Loop
    }
}

