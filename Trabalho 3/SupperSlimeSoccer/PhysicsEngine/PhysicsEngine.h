#ifndef _PE_PENGINE_
#define _PE_PENGINE_

#include "ObjectCollision.h"
#include "PhysicsWorld.h"
#include "PhysicConstants.h"

namespace CGPhysicsEngine
{

class PhysicsEngine
{
private:
	ObjectCollision * _collisionModel;
	PhysicsWorld * _world;

	static float _friction;
	static float _gravitationalAcceleration;
public:
	PhysicsEngine(void);
	~PhysicsEngine(void);

	ObjectCollision * GetObjectCollisionModel();

	void Process(PhysicEnabledObject * obj, int deltaTimeMilis);

	static double GetFriction();
	static double GetGravitationalAcceleration();
};

}
#endif