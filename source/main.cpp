#include "MicroBit.h"

MicroBit uBit;

int main()
{
    uBit.init();

    //uBit.display.scroll("Hello Yimaj 123");

    codal::Image img(5, 5);
    bool motorToggle = false;
    while (true) {
        // do nothing...
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                img.setPixelValue(x, y, 255);
                uBit.display.image = img;
                target_wait_us(50000); // waits for 50,000 microseconds
                img.setPixelValue(x, y, 0);
            }
        }

        if (motorToggle) {
            uBit.io.P0.setServoValue(0);
        } else {
            uBit.io.P0.setServoValue(180);
        }
    }
}

