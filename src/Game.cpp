#include <algorithm>

#include "Game.h"
#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Actor.h"
#include "Camera.h"
#include "Object3D.h"

namespace Brix {
    // void Game::renderText(std::string text, int x, int y, int h, int w) {
    //     TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
    //     SDL_Color White = {255, 255, 255};
    //     SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text.c_str(), White); 
    //     SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    //     SDL_Rect FPSMessage; 
    //     FPSMessage.x = 0; 
    //     FPSMessage.y = 0; 
    //     FPSMessage.w = 100; 
    //     FPSMessage.h = 100; 
    //     SDL_RenderCopy(renderer, messageTexture, NULL, &FPSMessage);
    //     SDL_FreeSurface(surfaceMessage);
    //     SDL_DestroyTexture(messageTexture);
    // }


    bool Game::initialize() {
        if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
        {
            SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
            return false;
        }
        
        window = SDL_CreateWindow("Brix Game", 100, 100, this->width, this->height, 0);
        if (!window)
        {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            return false;
        }
        
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer)
        {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            return false;
        }
        // TTF_Init(); 

        this->camera = new Camera(this, Math::Vector3(0.5, 1, -4));
        float NEAR = this->camera->nearPlane; 
        float FAR = this->camera->farPlane; 
        float RIGHT = tan(camera->hFov / 2); 
        float TOP = tan(camera->vFov / 2);

        float m00 = 1 / RIGHT, m11 = 1 / TOP;
        float m22 = (FAR + NEAR) / (FAR - NEAR), m32 = -2 * NEAR * FAR / (FAR - NEAR); 
        float projectionMatrixVals[4][4] = {
            {m00, 0, 0, 0},
            {0, m11, 0, 0}, 
            {0, 0, m22, 1}, 
            {0, 0, m32, 0}
        };
        this->projectionMatrix = Math::Matrix4(projectionMatrixVals);

        float HW = this->width / 2, HH = this->height / 2; 
        float toScreenMatrixVals[4][4] = {
            {HW, 0, 0, 0},
            {0, -HH, 0, 0}, 
            {0, 0, 1, 0}, 
            {HW, HH, 0, 1}
        };
        this->toScreenMatrix = Math::Matrix4(toScreenMatrixVals);

        // creating the object vertexes and faces
        std::vector<Math::Vector4> vertexes = {
            Math::Vector4(0, 0, 0, 1), Math::Vector4(0, 1, 0, 1), Math::Vector4(1, 1, 0, 1), Math::Vector4(1, 0, 0, 1), 
            Math::Vector4(0, 0, 1, 1), Math::Vector4(0, 1, 1, 1), Math::Vector4(1, 1, 1, 1), Math::Vector4(1, 0, 1, 1)
        };
        std::vector<std::vector<int>> faces = {
            {0, 1, 2, 3}, {4, 5, 6, 7}, {0, 4, 5, 1}, 
            {2, 3, 7, 6}, {0, 3, 7, 4}, {1, 2, 6, 5}
        };
        this->object3D = new Object3D(vertexes, faces); 
        return true;
    }

    void Game::runGame(){
        while(this->isRunning) {
            ticksCount = SDL_GetTicks();
            this->processInput(); 
            this->updateGame(); 
            this->generateOutput(); 
            uint32_t delta = SDL_GetTicks() - ticksCount; 
            float fps = 1000.0f / (double) delta; 
            // renderText(std::to_string(fps), 0, 0, 25, 100);
        }
    }; 

    void Game::processInput(){
        SDL_Event event;
        if(SDL_PollEvent(&event)) {
            this->camera->control(event); 
            if(event.key.keysym.sym == SDLK_ESCAPE) {
                this->isRunning = false; 
            }
        }
    }; 

    void Game::updateGame(){
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(this->renderer);
        this->object3D->projectToScreen(this); 
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