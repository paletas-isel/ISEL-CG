#ifndef _PE_SPHEREOBJ_
#define _PE_SPHEREOBJ_

#include "PhysicEnabledObject.h"
#include "BoundingSphere.h"
#include "cggl\MathUtils.h"

namespace CGPhysicsEngine
{

class SpherePhysicObject : public PhysicEnabledObject, public BoundingSphere
{
private: 
	float _radius;
public:
	SpherePhysicObject(cggl::Vector3 position, float mass, float radius, float maximumVelocity);
	~SpherePhysicObject(void);

	float GetRadius();
	cggl::Vector3 GetCenter() { return GetPosition(); }
};

}

#endif
