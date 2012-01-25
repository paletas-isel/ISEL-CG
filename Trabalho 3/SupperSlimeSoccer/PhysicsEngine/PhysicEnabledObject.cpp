#include "PhysicEnabledObject.h"
#include "PhysicsEngine.h"

using namespace cggl;

namespace CGPhysicsEngine
{

PhysicEnabledObject::PhysicEnabledObject(Vector3 position, float mass)
{
	_position = position;
	_mass = mass;
	_acceleration = Vector3::ZERO;
}

PhysicEnabledObject::~PhysicEnabledObject(void)
{
}

void PhysicEnabledObject::SetMass(float mass)
{
	_mass = mass;
}

float PhysicEnabledObject::GetMass()
{
	return _mass;
}

void PhysicEnabledObject::SetPosition(Vector3 position)
{
	_position = position;
}

Vector3 PhysicEnabledObject::GetPosition()
{
	return _position;
}

void PhysicEnabledObject::AddForce(Vector3 force)
{
	if(force.x != 0 || force.y != 0)
	{
		float friction = PhysicsEngine::GetFriction();

		if(force.x != 0 && force.x < friction)
			friction = force.x;
		else if(force.y != 0 && force.y < friction)
			friction = force.y;

		_acceleration += ((force / GetMass()) - (friction * PhysicsEngine::GetGravitationalAcceleration()));		
	}
	else
		_acceleration += force / GetMass();
}

void PhysicEnabledObject::SetVelocity(Vector3 velocity)
{
	_velocity = velocity;
}

Vector3 PhysicEnabledObject::GetVelocity()
{
	return _velocity;
}
	
void PhysicEnabledObject::SetAcceleration(Vector3 acceleration)
{
	_acceleration = acceleration;
}
	
Vector3 PhysicEnabledObject::GetAcceleration()
{
	return _acceleration;
}

}