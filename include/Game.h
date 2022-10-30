#include "SDL2/SDL.h"
#include <CommonHeaders.h>

namespace Brix {
    class Game
    {
    public:
        Game() : 
            window(nullptr), 
            renderer(nullptr), 
            isRunning(true), 
            doUpdateActors(true), 
            width(1024), 
            height(768)
        {}
        ~Game();

        bool initialize(); 
        void runGame(); 
        void shutdown();

        void addActor(class Actor* actor);
        void removeActor(class Actor* actor);  

        int width, height; 
        SDL_Window* window; 
        SDL_Renderer* renderer; 
        class Camera* camera; 
        Math::Matrix4 projectionMatrix, toScreenMatrix; 

    private: 
        void renderText(std::string text, int x, int y, int h, int w); 
        void processInput(); 
        void updateGame(); 
        void generateOutput(); 

        std::vector<class Actor*> actors; 
        std::vector<class Actor*> pendingActors; 
        std::vector<class SpriteComponent*> sprites; 

        class Object3D* object3D; 

        bool isRunning; 
        bool doUpdateActors; 
        uint32_t ticksCount;  
    };

}