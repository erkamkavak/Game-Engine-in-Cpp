#include "Actor.h"
#include "Component.h"

namespace Brix {
    Component::Component(Actor* owner, int updateOrder) 
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
}