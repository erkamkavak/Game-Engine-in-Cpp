#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(class Game* game) 
    : mState(State::Active)
    , mPosition(Vector2::zero)
    , mScale(1.0f)
    , mRotation(0.0f)
    , mGame(game)
{
    mGame->addActor(this); 
}; 

Actor::~Actor() {
    mGame->removeActor(this); 
    while(!mComponents.empty()) {
        delete mComponents.back(); 
    }
}; 

void Actor::update(float deltaTime) {
    if(getState() == State::Active) {
        updateComponents(deltaTime);
        updateActor(deltaTime); 
    }
}; 

void Actor::updateComponents(float deltaTime) {
    for (auto component : mComponents)
	{
		component->update(deltaTime);
	}
}; 

void Actor::updateActor(float deltaTime) {
    // empty for now
}; 

// Add component to the component list of the actor based on the update order of the component
void Actor::addComponent(Component* component) {
    int componentUpdateOrder = component->getUpdateOrder(); 
    auto iter = mComponents.begin(); 
    while(iter != mComponents.end()) {
        if(componentUpdateOrder < (*iter)->getUpdateOrder()) {
            break; 
        }
        iter++; 
    }
    mComponents.insert(iter, component); 
}; 

void Actor::removeComponent(class Component* component) {
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}; 
