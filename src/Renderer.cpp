#include "Renderer.h"
#include <SDL_image.h>

namespace Brix {
    Renderer::Renderer() {}

    bool Renderer::initialize(int screenWidth, int screenHeight) {
        this->screenWidth = screenWidth, this->screenHeight = screenHeight; 

        window = SDL_CreateWindow("Brix Game", 100, 100, this->screenWidth, this->screenHeight, 0);
        if (!window)
        {
            SDL_Log("Failed to create SDL window: %s", SDL_GetError());
            return false;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer)
        {
            SDL_Log("Failed to create SDL renderer: %s", SDL_GetError());
            return false;
        }

        this->camera = new Camera(this->screenHeight, this->screenWidth, Math::Vector3(0.5, 1, -4));
        float NEAR = camera->nearPlane; 
        float FAR = camera->farPlane; 
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

        float HW = this->screenWidth / 2, HH = this->screenHeight / 2; 
        float toScreenMatrixVals[4][4] = {
            {HW, 0, 0, 0},
            {0, -HH, 0, 0}, 
            {0, 0, 1, 0}, 
            {HW, HH, 0, 1}
        };
        this->toScreenMatrix = Math::Matrix4(toScreenMatrixVals);

        this->createActors(); 
        return true; 
    }; 

    void Renderer::createActors() {
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
    }

    void Renderer::render() {
        this->clearScreen(); 
        this->object3D->projectToScreen(this);
    }

    void Renderer::clearScreen() {
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(this->renderer);
    };

    void Renderer::renderObject3D(const std::vector<Math::Vector2>& vertexes, 
                const std::vector<std::vector<int>>& faces) {
        SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        for(int i = 0; i < faces.size(); i++) {
            std::vector<int> face = faces[i];
            for(int i = 0; i < face.size() - 1; i++) {
                Math::Vector2 faceCorner = vertexes[face[i]];
                Math::Vector2 faceNextCorner = vertexes[face[i + 1]];
                SDL_RenderDrawLine(this->renderer, 
                    faceCorner.x, faceCorner.y, faceNextCorner.x, faceNextCorner.y);
            } 
        }
        SDL_RenderPresent(this->renderer); 
    };

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
}