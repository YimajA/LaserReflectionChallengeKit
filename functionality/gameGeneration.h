#include "mbed.h"

#ifndef GAME_GENERATION_INCLUDED
#define GAME_GENERATION_INCLUDED

class GameGenerator {
    public:
    struct GameConfig {
        struct MirrorConfig {
            bool disabled;
            int startingPosition; // in degrees
        };

        MirrorConfig mirrors[6];
    };

    static GameConfig generateGame();
};

#endif // GAME_GENERATION_INCLUDED
