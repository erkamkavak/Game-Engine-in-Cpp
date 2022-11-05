#ifndef _INPUT_MANAGER_CLASS_
#define _INPUT_MANAGER_CLASS_

#include <GameAction.h>
#include <Renderer.h>
#include <Camera.h>

namespace Brix
{
    class InputManager {
    public:
        InputManager();
        ~InputManager();        

        bool initialize(Renderer renderer); 
        void shutdown(); 

        void processInput(bool &isRunning, uint32_t delta); 
    private: 
        Renderer* renderer; 
        Camera* rendererCamera; 

        void handleEvent(SDL_Event* event, bool &isRunning, uint32_t deltaT);

    };
}
#endif