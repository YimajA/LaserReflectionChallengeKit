#undef __ARM_FP
// #include "mbed.h"
 #include "functionality/gameGeneration.h"
#include <cstdio>
// main() runs in its own thread in the OS
int main()
{
    printf("start\n");
    GameGenerator newGame;
    newGame.generateGame();
    
}

