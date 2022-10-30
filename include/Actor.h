#include "Math.h"
#include <vector>

namespace Brix {

    class Actor
    {
    public:
        enum State {
            Active, 
            Paused, 
            Dead
        }; 
        Actor(class Game* game);
        virtual ~Actor();

        void update(float deltaTime); 
        void updateComponents(float deltaTime); 
        virtual void updateActor(float deltaTime); 

        void addComponent(class Component* component); 
        void removeComponent(class Component* component);

        // Getters and Setters
        const Math::Vector2& getPosition() const { return mPosition; }
    	void setPosition(const Math::Vector2& pos) { mPosition = pos; }
    	float getScale() const { return mScale; }
    	void setScale(float scale) { mScale = scale; }
    	float getRotation() const { return mRotation; }
    	void setRotation(float rotation) { mRotation = rotation; }
    	State getState() const { return mState; }
    	void setState(State state) { mState = state; }

    	class Game* getGame() { return mGame; }


    private: 
        State mState; 

        Math::Vector2 mPosition; 
        float mScale;
        float mRotation; 

        std::vector<class Component*> mComponents; 
        class Game* mGame; 

    };

}