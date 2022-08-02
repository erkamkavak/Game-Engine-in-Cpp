#include "Actor.h"
#include "Component.h"



Component::Component(Actor* owner, int updateOrder = 100) 
    : mOwnerActor(owner)
    , mUpdateOrder(updateOrder)
{
    mOwnerActor->addComponent(this); 
};

Component::~Component() {
    mOwnerActor->removeComponent(this); 
};

void Component::update(float deltaTime){

};