#include "Camera.h"

namespace Brix {

    Camera::Camera(int screenHeight, int screenWidth, Math::Vector3 position) {
        this->position = Math::Vector4::fromVector3(position); 
        this->view = Math::Matrix4(); 
        this->hFov = Math::pi / 3;
        this->vFov = this->hFov * ((float)screenHeight / (float) screenHeight);
        this->nearPlane = 0.1; 
        this->farPlane = 100; 
        this->movingSpeed = 0.002; 
        this->rotatingSpeed = 0.001;   
    }; 

    Camera::~Camera() {

    };
    
    void Camera::control(SDL_Event event, uint32_t delta) {
        switch(event.type) {
            // Look for a keypress
            case SDL_KEYDOWN: 
                switch (event.key.keysym.sym)
                {
                case SDLK_w: 
                    this->movePosition(2, 1, delta); 
                    break; 
                case SDLK_s: 
                    this->movePosition(2, -1, delta);
                    break; 
                case SDLK_a: 
                    this->movePosition(0, -1, delta); 
                    break; 
                case SDLK_d: 
                    this->movePosition(0, 1, delta); 
                    break;
                case SDLK_e: 
                    this->movePosition(1, -1, delta); 
                    break; 
                case SDLK_q: 
                    this->movePosition(1, 1, delta); 
                    break;
                case SDLK_RIGHT:
                    this->rotateYaw(this->rotatingSpeed * delta);
                    break;
                case SDLK_LEFT:
                    this->rotateYaw(-this->rotatingSpeed * delta); 
                    break;
                case SDLK_UP: 
                    this->rotatePitch(-this->rotatingSpeed * delta);
                    break; 
                case SDLK_DOWN: 
                    this->rotatePitch(this->rotatingSpeed * delta);
                    break; 
                default:
                    break;
                }
                break; 
            default: 
                break;
        }
    }; 

    void Camera::movePosition(int axis, int direction, uint32_t delta) {
        this->position += this->view.rows[axis] * (this->movingSpeed * delta * direction); 
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