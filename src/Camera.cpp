#include "Camera.h"
#include "Game.h"

namespace Brix {

    Camera::Camera(Game* game, Math::Vector3 position) {
        this->game = game; 
        this->position = Math::Vector4::fromVector3(position); 
        this->view = Math::Matrix4(); 
        this->hFov = Math::pi / 3;
        this->vFov = this->hFov * ((float)game->height / (float)game->width); 
        this->nearPlane = 0.1; 
        this->farPlane = 100; 
        this->movingSpeed = 0.2; 
        this->rotatingSpeed = 0.01;   
    }; 

    Camera::~Camera() {

    };
    
    void Camera::control(SDL_Event event) {
        switch (event.key.keysym.sym)
        {
        case SDLK_w: 
            this->movePosition(2, 1); 
            break; 
        case SDLK_s: 
            this->movePosition(2, -1);
            break; 
        case SDLK_a: 
            this->movePosition(0, -1); 
            break; 
        case SDLK_d: 
            this->movePosition(0, 1); 
            break;
        case SDLK_e: 
            this->movePosition(1, -1); 
            break; 
        case SDLK_q: 
            this->movePosition(1, 1); 
            break;
        case SDLK_RIGHT:
            this->rotateYaw(this->rotatingSpeed);
            break;
        case SDLK_LEFT:
            this->rotateYaw(-this->rotatingSpeed);                
            break;
        case SDLK_UP: 
            this->rotatePitch(-this->rotatingSpeed);
            break; 
        case SDLK_DOWN: 
            this->rotatePitch(this->rotatingSpeed);
            break; 
        default:
            break;
        }
    }; 

    void Camera::movePosition(int axis, int direction) {
        this->position += this->view.rows[axis] * (this->movingSpeed * direction); 
    }; 

    void Camera::rotateYaw(double angle) {
        Math::Matrix4 rotationMatrix = Math::Matrix4::createRotationY(angle); 
        this->view = this->view * rotationMatrix;
    }; 

    void Camera::rotatePitch(double angle) {
        Math::Matrix4 rotationMatrix = Math::Matrix4::createRotationX(angle); 
        this->view = this->view * rotationMatrix;
    }; 

    Math::Matrix4 Camera::getExtrinsicMatrix() {
        Math::Vector3 translationPos = Math::Vector3(-this->position.x, -this->position.y, -this->position.z);
        Math::Matrix4 translationMatrix = Math::Matrix4::createTranslation(translationPos);
        Math::Matrix4 rotationMatrix = Math::Matrix4::transpose(this->view);
        Math::Matrix4 extrinsicMatrix = translationMatrix * rotationMatrix;
        return extrinsicMatrix;
    }; 
}