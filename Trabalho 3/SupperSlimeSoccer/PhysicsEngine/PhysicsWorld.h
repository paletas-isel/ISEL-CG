#ifndef _PE_PWORLD_
#define _PE_PWORLD_

#include <list>
#include "PhysicEnabledObject.h"
#include "cggl\MathUtils.h"

namespace CGPhysicsEngine
{

class PhysicsWorld
{
private:
	std::list<PhysicEnabledObject *> _world;

public:
	PhysicsWorld(void);
	~PhysicsWorld(void);

	void AddObject(PhysicEnabledObject * obj);
	void RemoveObject(PhysicEnabledObject * obj);

	PhysicEnabledObject * Single(bool (*Predicate)(PhysicEnabledObject *));
};

}

#endif