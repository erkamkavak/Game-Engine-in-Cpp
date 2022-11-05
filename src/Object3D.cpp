#include <Object3D.h>
#include <Renderer.h>

namespace Brix
{
    Object3D::Object3D(std::vector<Math::Vector4> vertexes, std::vector<std::vector<int>> faces) : 
        vertexes(vertexes),
        faces(faces)
    {
    }; 

    Object3D::~Object3D() {

    };

    void Object3D::projectToScreen(Renderer* renderer) {
        std::vector<Math::Vector4> vertexesProcessed(vertexes.size()); 
        std::vector<Math::Vector2> screenVertexes(vertexes.size()); 
        Math::Matrix4 cameraExtrinsicMatrix = renderer->getCamera()->getExtrinsicMatrix(); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexesProcessed[i] = vertexes[i]; 
            // convert vertexes to camera space
            vertexesProcessed[i] = vertexesProcessed[i] * cameraExtrinsicMatrix;
            // using projection matrix, transfer camera space vertexes to clip space  
            vertexesProcessed[i] = vertexesProcessed[i] * renderer->getProjectionMatrix(); 
            // normalize the values of vertexes(using the 4'th value of each row -> w should be 1 for each row)
            vertexesProcessed[i].normalize();
            // clamp the values clip space vertexes between -2 and 2
            vertexesProcessed[i].x = Math::clamp(vertexesProcessed[i].x, -2.0f, 2.0f); 
            vertexesProcessed[i].y = Math::clamp(vertexesProcessed[i].y, -2.0f, 2.0f); 
            vertexesProcessed[i].z = Math::clamp(vertexesProcessed[i].z, -2.0f, 2.0f); 
            // convert clip space vertexes to screen space vertexes((0, 0) coordinate becomes left up side)
            vertexesProcessed[i] = vertexesProcessed[i] * renderer->getToScreenMatrix(); 
            // since the screen is only 2D, we slice the vertexes
            screenVertexes[i] = Math::Vector2(vertexesProcessed[i].x, vertexesProcessed[i].y);
        }
        // now we display vertexes and faces
        renderer->renderObject3D(screenVertexes, faces);
    }; 

    void Object3D::translate(Math::Vector3 pos){
        Math::Matrix4 translateMat = Math::Matrix4::createTranslation(pos); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexes[i] = vertexes[i] * translateMat; 
        }
    }; 

    void Object3D::scale(int scale_size){
        Math::Matrix4 scaleMat = Math::Matrix4::createScale(scale_size); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexes[i] = vertexes[i] * scaleMat; 
        }
    }; 

    void Object3D::rotateX(double angle){
        Math::Matrix4 rotationMat = Math::Matrix4::createRotationX(angle); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexes[i] = vertexes[i] * rotationMat; 
        }
    }; 

    void Object3D::rotateY(double angle){
        Math::Matrix4 rotationMat = Math::Matrix4::createRotationY(angle); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexes[i] = vertexes[i] * rotationMat; 
        }

    }; 

    void Object3D::rotateZ(double angle){
        Math::Matrix4 rotationMat = Math::Matrix4::createRotationZ(angle); 
        for(int i = 0; i < vertexes.size(); i++) {
            vertexes[i] = vertexes[i] * rotationMat; 
        }
    }; 
}
