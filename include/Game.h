#include "SDL2/SDL.h"
#include <CommonHeaders.h>
#include <Renderer.h>
#include <InputManager.h>

namespace Brix {
    class Game
    {
    public:
        Game();
        ~Game();

        bool initialize(); 
        void runGame(); 
        void shutdown();

        void addActor(class Actor* actor); 
        void removeActor(class Actor* actor); 
    private: 
        void generateOutput(); 

        InputManager inputManager; 
        Renderer renderer; 

        bool isRunning; 
        bool doUpdateActors; 
    };

}