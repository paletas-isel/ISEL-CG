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
	PhysicsWorld _world;

	static float _staticFrictionCoeficient;
	static float _kineticFrictionCoeficient;
	static float _gravitationalAcceleration;

	float _worldBottomLimit;	
public:
	PhysicsEngine(float worldBottomLimit);
	~PhysicsEngine(void);
	
	void Process(PhysicEnabledObject& obj, int deltaTimeMilis);
	
	void AddForce(PhysicEnabledObject& obj, cggl::Vector3 force);

	PhysicsWorld& GetWorld() { return _world; }

	void RegisterObject(PhysicEnabledObject& obj);

	static float GetStaticFrictionCoeficient() { return _staticFrictionCoeficient; }
	static float GetKineticFrictionCoeficient() { return _kineticFrictionCoeficient; }
	static float GetGravitationalAcceleration() { return _gravitationalAcceleration; }
};

}
#endif