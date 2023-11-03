#include "gameGeneration.h"
#include <cstdio>
#include<cstdlib>
#include<iostream>
GameGenerator::GameConfig* GameGenerator::generateGame() {
    // Winning combinations
    int combination1[6] = {-23, -25, -21, 0, -15, 5};
    int combination2[6] = {0, 0, -51, 15, 0, 0};
    int combination3[6] = {12, 0, -21, 0, 0, 0}; //
    int combination4[6] = {0, 0, -23, 0, 83, 0};
    int combination5[6] = {6, -35, 35, 0, 0, 8}; //

    int* combinationArray[5] = {combination1, combination2, combination3, combination4, combination5};
    
    // Providing a seed value
    int numMirrorsDisabled = rand() % 2 + 1; printf("Number of disabled mirrors: %i\n", numMirrorsDisabled);
    int chosenCombination = rand() % 5; //choose winning combination

    GameGenerator::GameConfig* initGame = new GameConfig;

    //initialize starting position with winning combination and un-disable all mirrors
    for (int i = 0; i < 6; i++) {
        initGame->mirrors[i].startingPosition = -combinationArray[chosenCombination][i];
        initGame->mirrors[i].disabled = false;
        printf("starting position: %i\n",initGame->mirrors[i].startingPosition);
    }

    // randomly disable no more than 2 mirrors
    for (int i = 0; i < numMirrorsDisabled; i++) {
        int mirrorSelect = rand() % 6;
        initGame->mirrors[mirrorSelect].disabled = true;
        printf("Disabled mirror: %i\n", mirrorSelect);
        // printf("Status of selected mirror: %d\n", initGame.mirrors[mirrorSelect].disabled);
    }
    printf("After randomization: \n");
    // randomly change values of non-disabled mirrors
    for (int i = 0; i < 6; i++) {
        if (initGame->mirrors[i].disabled == false) {
            int random = rand() % 180 -90;
            initGame->mirrors[i].startingPosition = random;
        }
        printf("Mirror no. %i: %i \n", i, initGame->mirrors[i].startingPosition);
    }

    return initGame;
}