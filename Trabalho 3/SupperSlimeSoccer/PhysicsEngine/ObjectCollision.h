#ifndef _PE_OBJCOLLISION_
#define _PE_OBJCOLLISION_

#include "PhysicEnabledObject.h"
#include "BoundingSphere.h"
#include "BoundingBox.h"
#include "BoundingVolume.h"

namespace CGPhysicsEngine
{


class ObjectCollision
{
private:
	ObjectCollision(void){}
	~ObjectCollision(void){}

	friend class PhysicsEngine;
public:
	bool Intersects(BoundingSphere& obj1, BoundingSphere& obj2);

	bool Intersects(BoundingSphere& obj1, BoundingBox& obj2);
	bool Intersects(BoundingBox& obj1, BoundingSphere& obj2);

	bool Intersects(BoundingBox& obj1, BoundingBox& obj2);

	void ProcessCollisionResponse(PhysicEnabledObject& obj1, PhysicEnabledObject& obj2);
};

}
#endif