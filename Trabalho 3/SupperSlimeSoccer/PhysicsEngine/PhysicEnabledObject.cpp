#include "PhysicEnabledObject.h"
#include "PhysicsEngine.h"

using namespace cggl;

namespace CGPhysicsEngine
{
	
PhysicEnabledObject::PhysicEnabledObject(Vector3 position, float mass, float maximumVelocity, Vector3 boundingBoxCenter, Vector3 boundingBoxDimensions) : BoundingBox(boundingBoxCenter, boundingBoxDimensions), _position(position)
{
	_maximumVelocity = maximumVelocity;
	_mass = mass;
	_acceleration = _force = Vector3::ZERO;
}

PhysicEnabledObject::PhysicEnabledObject(Vector3 position, float mass, float maximumVelocity, Vector3 boundingBoxDimensions) : BoundingBox(position, boundingBoxDimensions), _position(position)
{
	_maximumVelocity = maximumVelocity;
	_mass = mass;
	_acceleration = _force = Vector3::ZERO;
}

PhysicEnabledObject::~PhysicEnabledObject(void)
{
}

float PhysicEnabledObject::GetMaximumVelocity()
{ 
	return _maximumVelocity; 
}

void PhysicEnabledObject::SetPosition(cggl::Vector3 position)
{ 
	_position.x = position.x; 
	_position.y = position.y; 
	_position.z = position.z; 
}




}