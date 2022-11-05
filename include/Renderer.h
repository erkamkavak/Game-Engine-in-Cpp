#ifndef _RENDERER_CLASS_
#define _RENDERER_CLASS_

#include "SDL2/SDL.h"
#include <Math.h>
#include <vector>
#include <Camera.h>
#include <Object3D.h>

namespace Brix
{
    class Renderer {
    public:
        Renderer();

        bool initialize(int screenWidth, int screenHeight); 
        void shutdown(); 

        void render(); 
        void clearScreen(); 

        Math::Matrix4 getProjectionMatrix() { return this->projectionMatrix; } 
        Math::Matrix4 getToScreenMatrix() { return this->toScreenMatrix; }
        Camera* getCamera() { return this->camera; }; 

        int getScreenWidth() { return this->screenWidth; }
        int getScreenHeight() { return this->screenHeight; } 

        void renderText(std::string text); 
        void renderImage();
        void renderMesh();  
        void renderObject3D(const std::vector<Math::Vector2>& vertexes, 
                const std::vector<std::vector<int>>& faces); 
    private: 
        void createActors(); 


        SDL_Window* window; 
        SDL_Renderer* renderer; 
        Camera* camera; 
        Math::Matrix4 projectionMatrix, toScreenMatrix; 
        Object3D* object3D; 

        int screenWidth, screenHeight; 
    };
}
#endif