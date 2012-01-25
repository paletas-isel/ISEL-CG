#ifndef _PE_SPHEREOBJ_
#define _PE_SPHEREOBJ_

#include "PhysicEnabledObject.h"
#include "cggl\MathUtils.h"

namespace CGPhysicsEngine
{

class SpherePhysicObject : public PhysicEnabledObject
{
private: 
	float _radius;

public:
	SpherePhysicObject(cggl::Vector3 position, float mass, float radius);
	~SpherePhysicObject(void);

	float GetRadius();
};

}

#endif
