#include "gameGeneration.h"
#include<cstdlib>
#include<iostream>

GameGenerator::GameConfig GameGenerator::generateGame() {
    // Todo
    // Providing a seed value
	srand((unsigned) time(NULL));
    int random = rand() % 360;
    return {};
}