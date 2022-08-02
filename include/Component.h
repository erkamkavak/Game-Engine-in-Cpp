
class Component
{
public:
    Component(class Actor* owner, int updateOrder = 100);
    virtual ~Component();

    virtual void update(float deltaTime);

    class Actor* getOwnerActor() { return mOwnerActor; }
    int getUpdateOrder() { return mUpdateOrder; } 

protected:
    class Actor* mOwnerActor;
    int mUpdateOrder;  

};