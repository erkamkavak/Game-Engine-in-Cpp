#include <algorithm>

#include "Game.h"
#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Actor.h"

namespace Brix {
    Game::Game() : 
        isRunning(true), 
        doUpdateActors(true) 
    { 
    }

    bool Game::initialize() {
        if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return false;
        }

        if(!this->renderer.initialize(1024, 768)){
            printf("Failed to initialize renderer.\n");
            return false;
        };

        if(!this->inputManager.initialize(this->renderer)){
            printf("Failed to initialize input manager.\n");
            return false;
        };

        return true;
    }

    void Game::runGame(){
        uint32_t ticksCount;
        uint32_t delta = SDL_GetTicks(); 

        while(this->isRunning) {
            ticksCount = SDL_GetTicks();

            this->inputManager.processInput(this->isRunning, delta);
            this->renderer.render(); 
            this->generateOutput(); 
            
            delta = SDL_GetTicks() - ticksCount; 
            float fps = 1000.0f / (double) delta; 
            // renderText(std::to_string(fps), 0, 0, 25, 100);
        }
    }; 
    
    void Game::generateOutput(){

    }; 

    void Game::addActor(Actor* actor) {

    };

    void Game::removeActor(Actor* actor) {

    };  

    void Game::shutdown(){

    }; 

    Game::~Game()
    {
    }

}