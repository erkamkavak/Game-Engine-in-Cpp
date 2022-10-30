#ifndef _CAMERA_CLASS_
#define _CAMERA_CLASS_

#include <CommonHeaders.h>
#include "SDL2/SDL.h"

namespace Brix
{
    class Camera {
    public:
        Camera(class Game* game, Math::Vector3 position); 
        virtual ~Camera();

        void control(SDL_Event event); 
        void movePosition(int axis, int direction); 
        void rotateYaw(double angle); 
        void rotatePitch(double angle); 
        Math::Matrix4 getExtrinsicMatrix(); 

        class Game* game; 
        Math::Vector4 position; 
        Math::Matrix4 view; 
        float hFov, vFov;
        float nearPlane, farPlane; 
        float movingSpeed, rotatingSpeed; 
    private: 
    };
}
#endif