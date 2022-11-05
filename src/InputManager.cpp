#include "InputManager.h"

namespace Brix {
    InputManager::InputManager() {}
    InputManager::~InputManager(){}

    bool InputManager::initialize(Renderer renderer) {
        this->renderer = &renderer; 
        this->rendererCamera = (this->renderer->getCamera());

        return true; 
    }; 

    void InputManager::processInput(bool &isRunning, uint32_t delta) {
        SDL_Event event; 

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) {
                isRunning = false; 
            }
            else{
                this->rendererCamera->control(event, delta);
                handleEvent(&event, isRunning, delta); 
            }
        }
    }

    void InputManager::handleEvent(SDL_Event * event, bool &isRunning, uint32_t deltaT) {
        bool isDown  = event->type == SDL_KEYDOWN;
        bool wasDown = event->type == SDL_KEYUP;
    }
}