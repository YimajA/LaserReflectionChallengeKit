#undef __ARM_FP
// #include "mbed.h"
//  #include "gameGeneration.h"
#include <cstdio>
// main() runs in its own thread in the OS
int main()
{
    printf("hello from Tamtest");
    GameGenerator::GameConfig newGame;
    newGame.generateGame();
    
}

