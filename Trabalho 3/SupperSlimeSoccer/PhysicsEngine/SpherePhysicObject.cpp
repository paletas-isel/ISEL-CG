#include "SpherePhysicObject.h"

using namespace cggl;

namespace CGPhysicsEngine
{

SpherePhysicObject::SpherePhysicObject(Vector3 position, float mass, float radius, float maximumVelocity = 0) : 
	PhysicEnabledObject(position, mass, maximumVelocity),
	BoundingSphere(radius)
{
	_radius = radius;
}


SpherePhysicObject::~SpherePhysicObject(void)
{
}

float SpherePhysicObject::GetRadius()
{
	return _radius;
}

}