#ifndef _PE_PWORLD_
#define _PE_PWORLD_

#include <list>
#include "BoundingVolume.h"
#include "cggl\MathUtils.h"

namespace CGPhysicsEngine
{

class PhysicsWorld
{
private:
	std::list<BoundingVolume *> _world;

public:
	PhysicsWorld(void);
	~PhysicsWorld(void);

	void AddObject(BoundingVolume * obj);
	void RemoveObject(BoundingVolume * obj);

	BoundingVolume * Single(bool (*Predicate)(BoundingVolume *));
};

}

#endif