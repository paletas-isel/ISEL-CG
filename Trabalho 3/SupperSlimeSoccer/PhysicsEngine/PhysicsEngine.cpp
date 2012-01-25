#include "PhysicsEngine.h"
#include "cggl\MathUtils.h"
#include <math.h>

using namespace cggl;

namespace CGPhysicsEngine
{
	
float PhysicsEngine::_friction = (float) CONCRETE_FRICTION;
float PhysicsEngine::_gravitationalAcceleration = (float) EARTH_GRAVITY_ACCELERATION;

PhysicsEngine::PhysicsEngine(void)
{
	_collisionModel = new ObjectCollision();
	_world = new PhysicsWorld();
}


PhysicsEngine::~PhysicsEngine(void)
{
	_collisionModel->~ObjectCollision();
}


ObjectCollision * PhysicsEngine::GetObjectCollisionModel()
{
	return _collisionModel;
}

void PhysicsEngine::Process(PhysicEnabledObject * obj, int deltaTimeMilis)
{		
	Vector3 acceleration = obj->GetAcceleration();
	if(acceleration.x != 0 || acceleration.y != 0 || acceleration.z != 0)
	{
		Vector3 position = obj->GetPosition();
		Vector3 velocity = obj->GetVelocity();

		float deltaT = (float) deltaTimeMilis / 1000;
		Vector3 newPosition = position + ((velocity * deltaT) + (0.5 * acceleration * pow(deltaT, 2)));
		obj->SetPosition(newPosition);

		Vector3 deltaD = newPosition - position;
		obj->SetVelocity(deltaD / deltaT);

		obj->AddForce(Vector3::ZERO);
	}
}

double PhysicsEngine::GetFriction()
{
	return _friction;
}

double PhysicsEngine::GetGravitationalAcceleration()
{
	return _gravitationalAcceleration;
}

}