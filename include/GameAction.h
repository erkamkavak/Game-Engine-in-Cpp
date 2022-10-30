#include "Math.h"
#include <vector>

namespace Brix {

    class GameAction
    {
    public:
        enum Behavior {
            NORMAL, 
            DETECT_INITAL_PRESS_ONLY // isPressed returns true only after the key is first pressed. 
        };

        enum State {
            RELEASED, 
            PRESSSED, 
            WAITING_FOR_RELEASE // for DETECT_INITAL_PRESS_ONLY situation
        };


        GameAction(std::string name);
        GameAction(std::string name, Behavior behavior);

        ~GameAction();

        void reset(); 
        void tap(); 
        void press(); 
        void press(int amount);
        void release(); 
        int getPressedAmount(); 
        bool isPressed();  

        State getState() const { return state; }
    	void setState(State state) { this->state = state; }

    private: 
        std::string name; 
        Behavior behavior; 
        int amount; 
        State state; 
    };    

}