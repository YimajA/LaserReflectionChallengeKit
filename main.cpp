#undef __ARM_FP
#include "mbed.h"
#include "hardware.h"

// main() runs in its own thread in the OS
int main()
{
    // EXAMPLE CODE - REMOVE MY CODE WHEN YOU GET A MERGE CONFLICT!

    // Start Setup
    AddressableLEDStrip::Color colors[6];


    // End Setup
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

        // End Loop
    }
}

