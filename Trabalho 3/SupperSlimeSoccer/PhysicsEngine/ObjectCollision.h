#ifndef _PE_OBJCOLLISION_
#define _PE_OBJCOLLISION_

#include "PhysicEnabledObject.h"
#include "SpherePhysicObject.h"
#include "BoxPhysicObject.h"

namespace CGPhysicsEngine
{


class ObjectCollision
{
private:
	ObjectCollision(void){}
	~ObjectCollision(void){}

	friend class PhysicsEngine;
public:
	bool AreObjectsColliding(PhysicEnabledObject * obj1, PhysicEnabledObject * obj2);

	bool AreObjectsColliding(SpherePhysicObject * obj1, SpherePhysicObject * obj2);

	bool AreObjectsColliding(SpherePhysicObject * obj1, BoxPhysicObject * obj2);
	bool AreObjectsColliding(BoxPhysicObject * obj1, SpherePhysicObject * obj2);

	bool AreObjectsColliding(BoxPhysicObject * obj1, BoxPhysicObject * obj2);

	void ProcessCollisionResponse(PhysicEnabledObject * obj1, PhysicEnabledObject * obj2);
};

}
#endif