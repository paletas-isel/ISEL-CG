#include "PhysicsEngine.h"
#include "cggl\MathUtils.h"
#include <math.h>

using namespace cggl;

#define MOVEMENT_THRESHOLD 0.01
#define ACCELERATION_THRESHOLD 0.0001

namespace CGPhysicsEngine
{
	
float PhysicsEngine::_staticFrictionCoeficient = (float) SLIME_ON_CONCRETE_STATIC_FRICTION_COEFICIENT;
float PhysicsEngine::_kineticFrictionCoeficient = (float) SLIME_ON_CONCRETE_KINETIC_FRICTION_COEFICIENT;
float PhysicsEngine::_gravitationalAcceleration = (float) EARTH_GRAVITY_ACCELERATION;

PhysicsEngine::PhysicsEngine(float worldBottomLimit)
{
	GetWorld().AddObject(new PhysicEnabledObject(Vector3(0, worldBottomLimit, 0), 999999999, 0, Vector3(30000, 5, 30000)));
}


PhysicsEngine::~PhysicsEngine(void)
{
}

inline bool ForceIsApplied(float force)
{
	return force != 0;
}

inline bool ObjectIsMoving(float currVelocity)
{
	return currVelocity != 0;
}
	
void PhysicsEngine::AddForce(PhysicEnabledObject& obj, Vector3 force)
{
	obj.AddForce(force);
}

float GetAccelerationFor1Dimension(float force, float mass, float staticFrictionCoeficient, float kineticFrictionCoeficient, float g, float currVelocity)
{
	float acceleration = 0;
	if(ForceIsApplied(force))
	{
		float maxFrictionForce;
		if(ObjectIsMoving(currVelocity))	
		{
			maxFrictionForce = kineticFrictionCoeficient * mass * g;
			acceleration = (force / mass) - (kineticFrictionCoeficient * g);
		}
		else
		{
			maxFrictionForce = staticFrictionCoeficient * mass * g;
			acceleration = (force / mass) - (staticFrictionCoeficient * g);
		}

		if(abs(force) <= maxFrictionForce) acceleration = 0;
	}
	else if(ObjectIsMoving(currVelocity) && abs(currVelocity) > MOVEMENT_THRESHOLD)
	{
		float maxFrictionForce;		

		maxFrictionForce = kineticFrictionCoeficient * mass * g;
		acceleration = (force / mass) - (kineticFrictionCoeficient * g) * (currVelocity / abs(currVelocity));
	}
	
	return acceleration;
}

float GetAccelerationForYDimension(float force, float mass, float g, float currVelocity, float currAcceleration, float currPos, float yBottomLimit)
{
	float acceleration = 0;
	if(!ForceIsApplied(force) && ObjectIsMoving(currVelocity))		
		force = mass * currAcceleration;
	
	acceleration = (force / mass) - g;
	
	if(abs(acceleration) < ACCELERATION_THRESHOLD) acceleration = 0;

	return acceleration;
}

float GetVelocityFor1Dimension(float maximumVelocity, float initialVelocity, float acceleration, float time)
{
	float velocity = initialVelocity + acceleration * time;
	float absVelo = abs(velocity);

	return (absVelo > maximumVelocity) ? maximumVelocity * (velocity / absVelo) : velocity;
}

float GetPositionFor1Dimension(float initialPosition, float initialVelocity, float acceleration, float time)
{
	return (float) (initialPosition + ((initialVelocity * time) + (0.5 * acceleration * pow(time, 2))));
}

PhysicEnabledObject * base;
bool IsColliding(PhysicEnabledObject * obj)
{
	return ObjectCollision::Intersects(*base, *obj);
}

void PhysicsEngine::RegisterObject(PhysicEnabledObject& obj)
{
	GetWorld().AddObject(&obj);
}

void PhysicsEngine::Process(PhysicEnabledObject& obj, int deltaTimeMilis)
{
	float deltaT = (float) deltaTimeMilis / 1000;
	Vector3 velocity = obj.GetVelocity();
	Vector3 acceleration = obj.GetAcceleration();
	Vector3 position = obj.GetPosition();
	
	float mass = obj.GetMass();
	float gravitationalAcceleration = (float) GetGravitationalAcceleration();	
	Vector3 force = obj.GetForce();

	if(velocity.x != 0 || velocity.y != 0 || velocity.z != 0)
	{		
		Vector3 newPosition(
			GetPositionFor1Dimension(position.x, velocity.x, acceleration.x, deltaT),
			GetPositionFor1Dimension(position.y, velocity.y, acceleration.y, deltaT),
			GetPositionFor1Dimension(position.z, velocity.z, acceleration.z, deltaT)
		);
		
		obj.SetPosition(newPosition);

		base = &obj;
		PhysicEnabledObject * collisioner = GetWorld().Single(IsColliding);

		if(collisioner != NULL)
		{
			ObjectCollision::ProcessCollisionResponse(*base, *collisioner);
		}
	}
	
	float staticFrictionCoeficient = (float) GetStaticFrictionCoeficient();
	float kineticFrictionCoeficient = (float) GetKineticFrictionCoeficient();

	Vector3 newAcceleration(
		GetAccelerationFor1Dimension(force.x, mass, staticFrictionCoeficient, kineticFrictionCoeficient, gravitationalAcceleration, velocity.x),
		GetAccelerationForYDimension(force.y, mass, gravitationalAcceleration, velocity.y, acceleration.y, position.y, _worldBottomLimit),
		GetAccelerationFor1Dimension(force.z, mass, staticFrictionCoeficient, kineticFrictionCoeficient, gravitationalAcceleration, velocity.z)
	);

	float maximumVelocity = obj.GetMaximumVelocity();

	Vector3 newVelocity(
		GetVelocityFor1Dimension(maximumVelocity, velocity.x, newAcceleration.x, deltaT),
		GetVelocityFor1Dimension(maximumVelocity, velocity.y, newAcceleration.y, deltaT),
		GetVelocityFor1Dimension(maximumVelocity, velocity.z, newAcceleration.z, deltaT)
	);
	
	obj.SetAcceleration(newAcceleration);
	obj.SetVelocity(newVelocity);
	obj.SetForce(Vector3::ZERO);


}

}