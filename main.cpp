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

    // Start Setup
    AddressableLEDStrip::Color colors[6];

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
    float phases[] = {0, 60, 120, 180, 240, 300};
    while (true) {
        // Start Loop
        
        for (int led = 0; 6 > led; led++) {
            float c = 1;
            float x = c * (1 - abs(fmodf(phases[led] / 60.0f, 2.0f) - 1));
            float rp, gp, bp;

            float h = phases[led];

            if (h < 60) {
                rp = c;
                gp = x;
                bp = 0;
            } else if (h < 120) {
                rp = x;
                gp = c;
                bp = 0;
            } else if (h < 180) {
                rp = 0;
                gp = c;
                bp = x;
            } else if (h < 240) {
                rp = 0;
                gp = x;
                bp = c;
            } else if (h < 300) {
                rp = x;
                gp = 0;
                bp = c;
            } else {
                rp = c;
                gp = 0;
                bp = x;
            }

            colors[led] = {(char)(rp * 255), (char)(gp * 255), (char)(bp * 255)};

            phases[led] += 1;
            if (phases[led] > 359) {
                phases[led] -= 360;
            }
        }

        hardware.addressableLEDs.set(colors, 6);
        wait_us(10000);

        //hardware.speaker.playToneSquare(400, 500);
        //hardware.speaker.playToneSquare(800, 500);
        //hardware.speaker.playToneSquare(1600, 500);
    }
}

