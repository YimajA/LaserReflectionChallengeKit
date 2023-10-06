#include "gameGeneration.h"
#include<cstdlib>
#include<iostream>
// GameGenerator::GameConfig initGame;
// Assuming the initial position (0 degree) of the mirrors is the result
// When game starts, some mirrors will randomly move to random angles
GameGenerator::GameConfig GameGenerator::generateGame() {
    // Todo
    // Providing a seed value
	srand((unsigned) time(NULL));
    int numMirrorsDisabled = rand() % 2;

    GameGenerator::GameConfig initGame;
    // GameConfig initial = new GameConfig(); 
    // initGame.generateGame();

    //un-disable all mirrors
    for (int i = 0; i < 6; i++) {
        initGame.mirrors[i].disabled = false;
    }

    // randomly select no more than 2 mirrors
    for (int i = 0; i < numMirrorsDisabled; i++) {
        int mirrorSelect = rand() % 6;
        initGame.mirrors[mirrorSelect].disabled = true;
    }

    for (int i = 0; i < 6; i++) {
        if (initGame.mirrors[i].disabled == false) {
            int random = rand() % 360;
            initGame.mirrors[i].startingPosition = random;
        }
    }
    return {};
}