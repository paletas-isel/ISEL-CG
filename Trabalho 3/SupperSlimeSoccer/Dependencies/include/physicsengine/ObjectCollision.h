#ifndef _PE_OBJCOLLISION_
#define _PE_OBJCOLLISION_

#include "PhysicEnabledObject.h"
#include "BoundingBox.h"

namespace CGPhysicsEngine
{


class ObjectCollision
{
private:
	ObjectCollision(void){}
	~ObjectCollision(void){}

	friend class PhysicsEngine;
public:
	
	static bool Intersects(BoundingBox& obj1, BoundingBox& obj2);

	static void ProcessCollisionResponse(PhysicEnabledObject& obj1, PhysicEnabledObject& obj2);
};

}
#endif