#ifndef _OBJECT3D_CLASS_
#define _OBJECT3D_CLASS_

#include <CommonHeaders.h>
#include <fstream>

namespace Brix
{
    class Object3D {
    public:
        Object3D(std::vector<Math::Vector4> vertexes, std::vector<std::vector<int>> faces); 
        virtual ~Object3D();

        void projectToScreen(class Renderer* renderer); 

        void translate(Math::Vector3 pos); 
        void scale(int scale_size); 
        void rotateX(double angle); 
        void rotateY(double angle); 
        void rotateZ(double angle); 

        static void readFromObjFile(std::string file_path) {
            std::vector<Math::Vector4> vertexes; 
            std::vector<std::vector<int>> faces; 
            std::ifstream file(file_path); 
            std::string line; 
            while (getline(file, line)) {
                if(line.rfind("v ", 0) == 0) {
                    
                } 
                else if(line.rfind("f", 0) == 0) {

                }
            } 
            file.close(); 
        } 
    private: 
        std::vector<Math::Vector4> vertexes; 
        std::vector<std::vector<int>> faces; 

        std::string font; 
        std::vector<std::string> face_colors; 
        bool draw_vertexes = false;
    };
}
#endif