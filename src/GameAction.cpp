#include "GameAction.h"

namespace Brix {
    GameAction::GameAction(std::string name) : name(name) {}
    GameAction::GameAction(std::string name, Behavior behavior) : name(name), behavior(behavior) {}

    GameAction::~GameAction() {
    }

    void GameAction::reset() {
        this->state = State::RELEASED;
        this->amount = 0; 
    }
    
    void GameAction::tap() {
        press(); 
        release(); 
    }

    void GameAction::press() {
        press(1); 
    }

    void GameAction::press(int amount) {
        if(this->state != State::WAITING_FOR_RELEASE) {
            this->amount += amount; 
            this->state = State::PRESSSED; 
        }
    }

    void GameAction::release() {
        this->state = State::RELEASED; 
    }

    int GameAction::getPressedAmount() {
        int result = this->amount;
        if(result != 0) {
            if(this->state == State::RELEASED) {
                this->amount = 0; 
            }
            else if(this->behavior == Behavior::DETECT_INITAL_PRESS_ONLY) {
                this->state = State::WAITING_FOR_RELEASE; 
                this->amount = 0; 
            }
        } 
        return result; 
    }
    
    bool GameAction::isPressed() {
        bool isPressed = this->getPressedAmount() != 0; 
        return isPressed; 
    }
}