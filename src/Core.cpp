#include "Core.h"


namespace Brix {
    Core::Core()
    {
        this->isRunning = true; 
    }
    
    Core::~Core()
    {
    }

    void Core::runGame(){
        while(this->isRunning) {
            this->processInput(); 
            this->updateGame(); 
            this->generateOutput(); 
        }
    }; 

    void Core::processInput(){

    }; 

    void Core::updateGame(){

    }; 

    void Core::generateOutput(){

    }; 

    void Core::shutdown(){

    }; 



}