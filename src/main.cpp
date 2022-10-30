#include "CommonHeaders.h"
#include "Game.h"

int main() {
    Brix::Log::init(); 

    Brix::Game game; 

    if(game.initialize()){
        BX_CORE_INFO("Game initialized and running.");
        game.runGame(); 
    }
    game.shutdown();
}