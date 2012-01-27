#ifndef _PE_PENGINE_
#define _PE_PENGINE_

#include "ObjectCollision.h"
#include "PhysicsWorld.h"
#include "PhysicConstants.h"
#include "PhysicEnabledObject.h"
#include "cggl\MathUtils.h"

namespace CGPhysicsEngine
{

class PhysicsEngine
{
private:
	ObjectCollision _collisionModel;
	PhysicsWorld _world;

	static float _staticFrictionCoeficient;
	static float _kineticFrictionCoeficient;
	static float _gravitationalAcceleration;

	float _worldBottomLimit;

public:
	PhysicsEngine(float worldBottomLimit);
	~PhysicsEngine(void);

	ObjectCollision& GetObjectCollisionModel() { return _collisionModel; }

	void Process(PhysicEnabledObject& obj, int deltaTimeMilis);
	
	void AddForce(PhysicEnabledObject& obj, cggl::Vector3 force);

	PhysicsWorld& GetWorld() { return _world; }

	static float GetStaticFrictionCoeficient() { return _staticFrictionCoeficient; }
	static float GetKineticFrictionCoeficient() { return _kineticFrictionCoeficient; }
	static float GetGravitationalAcceleration() { return _gravitationalAcceleration; }
};

}
#endif