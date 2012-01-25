#ifndef _PE_PLANEPO_
#define _PE_PLANEPO_

#include "PhysicEnabledObject.h"

namespace CGPhysicsEngine
{

class BoxPhysicObject : public PhysicEnabledObject
{
private:
	cggl::Vector3 * _normals;
	cggl::Vector3 _dimension;

public:
	BoxPhysicObject(cggl::Vector3 position, cggl::Vector3 dimensions, float mass, cggl::Vector3 * normals);
	~BoxPhysicObject(void);

	cggl::Vector3 * GetNormals();
	cggl::Vector3 GetDimension();
	
};

}

#endif