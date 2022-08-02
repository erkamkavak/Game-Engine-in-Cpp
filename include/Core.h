#include <iostream>
#include "SDL/SDL.h"

namespace Brix {
    class Core
    {
    private:
        /* data */
    public:
        Core();
        ~Core();
        void initialize(); 
        void runGame(); 
        void shutdown();

    private: 
        void processInput(); 
        void updateGame(); 
        void generateOutput(); 

        bool isRunning; 
    };

}