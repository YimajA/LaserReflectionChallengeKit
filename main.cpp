#include <ratio>
#undef __ARM_FP
#include "mbed.h"
#include "hardware.h"
#include "userInterface.h"
#include "mirrorModule.h"
#include "gameGeneration.h"

void startGame(MirrorModule* mirrors);

void endGame(bool didWin);
//   mirrors[6] = new MirrorModule();

// main() runs in its own thread in the OS
int main()
{
    Timer timer;
    timer.start();
    Timer sensorTimer;

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

    int lastSelected = UserInterface::getMirrorSelected();
    bool oldRead = false;
    bool currRead = false;
    bool isGameRunning = false;
    bool wasSensorHit = false;

    
    // End Setup

    //Yimaj
    while (true) {
        // Start Loop
        wait_us(500);

        // Read user input and test the UserInterface functions
        int selectedMirror = UserInterface::getMirrorSelected();
        int mirrorRotation = UserInterface::getMirrorRotation();
        bool buttonPushed = UserInterface::isButtonPushed();
        int leftEncoderRead = hardware.leftKnob.read();
        int rightEncoderRead = hardware.rightKnob.read();
        
         mirrors[selectedMirror].setAngle(mirrorRotation);
         mirrors[selectedMirror].setMode(MirrorModule::SELECTED);
         if (lastSelected != selectedMirror) {
             mirrors[lastSelected].setMode(MirrorModule::DEFAULT);
         }
        // Print out the selected mirror and rotation for testing
        //press once start press again end
        currRead = UserInterface::isButtonPushed();
        
        if (oldRead == false && currRead == true) {
            isGameRunning = !isGameRunning;
            if (isGameRunning) {
                // new value, so game should start
                startGame(mirrors);
            } else {
                endGame(false);
            }
        }
        oldRead = currRead;
       
        if (isGameRunning) {
            // TODO: code to run while the game is running
            bool sensorHit = hardware.lightSensor.read() < 0.5;
            if (sensorHit && !wasSensorHit)
            {
                sensorTimer.reset();
                sensorTimer.start();
            } else if (sensorHit && sensorTimer.elapsed_time().count() > 1000000) {
                endGame(true);
            }
            wasSensorHit = sensorHit;
        }

/*
        //Mode: WIN
        bool sensorRead = hardware.lightSensor.read();

        if (sensorRead == false) {
            hardware.speaker.playToneSin(698, 500);
            hardware.speaker.playToneSin(880, 500);
            hardware.speaker.playToneSin(783, 500);
            hardware.speaker.playToneSin(932, 500);
            hardware.speaker.playToneSin(1318, 500);
            hardware.speaker.playToneSin(1318, 250);
            hardware.speaker.playToneSin(1318, 250);
            hardware.speaker.playToneSin(1396, 250);

        }

*/
        // if (timer.elapsed_time().count() > 1000000) {
        //     timer.reset();
        //     printf("Left Encoder Reads: %d\n", leftEncoderRead);
        //     printf("Right Encoder Reads: %d\n", rightEncoderRead);
        //     printf("Selected Mirror: %d\n", selectedMirror);
        //     printf("Mirror Rotation: %d degrees\n", mirrorRotation);
        //     printf("Button Pushed: %s\n", buttonPushed ? "Yes" : "No");
        // }
        
        lastSelected = selectedMirror;
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

void startGame( MirrorModule* mirrors) {
    hardware.laser.write(1);
    GameGenerator newGame;
    GameGenerator::GameConfig gameConfig;
    GameGenerator::GameConfig *newMirrors = newGame.generateGame();
    // gameConfig.mirrors[]
    for (int i = 0; i < 6; i++) {
        // int angle = gameConfig.mirrors[i].startingPosition;
        int angle = newMirrors->mirrors[i].startingPosition;
        mirrors[i].setAngle(angle); 
        UserInterface::setMirrorAngle(angle, i);
        UserInterface::setMirrorDisabled(i, newMirrors->mirrors[i].disabled);
        mirrors[i].setMode(newMirrors->mirrors[i].disabled ? MirrorModule::DISABLED : MirrorModule::DEFAULT);
        printf("angle: %i\n", angle);
    }
}

void endGame(bool didWin) {
    if (didWin) {
        // play jingle
        hardware.speaker.playToneSin(698, 500);
        hardware.speaker.playToneSin(880, 500);
        hardware.speaker.playToneSin(783, 500);
        hardware.speaker.playToneSin(932, 500);
        hardware.speaker.playToneSin(1318, 500);
        hardware.speaker.playToneSin(1318, 250);
        hardware.speaker.playToneSin(1318, 250);
        hardware.speaker.playToneSin(1396, 250);
    }

    hardware.laser.write(0);
}