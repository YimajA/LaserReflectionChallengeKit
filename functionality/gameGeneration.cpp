#include "gameGeneration.h"
#include<cstdlib>
#include<iostream>
GameGenerator::GameConfig initGame;
// Assuming the initial position (0 degree) of the mirrors is the result
// When game starts, some mirrors will randomly move to random angles
GameGenerator::GameConfig GameGenerator::generateGame() {
    // Todo
    // Providing a seed value
	srand((unsigned) time(NULL));
    int numMirrorsDisabled = rand() % 2;

    GameConfig initial = new GameConfig(); 

    //un-disable all mirrors
    for (int i = 0; i < 6; i++) {
        GameConfig::mirrors[i].disabled = false;
    }

    // randomly select no more than 2 mirrors
    for (int i = 0; i < numMirrorsDisabled; i++) {
        int mirrorSelect = rand() % 6;
        GameConfig::mirrors[mirrorSelect].disabled = true;
    }

    for (int i = 0; i < 6; i++) {
        if (GameConfig::mirrors[i].disabled == false) {
            int random = rand() % 360;
            GameConfig::mirrors[i].startingPosition = random;
        }
    }
    return {};
}