#include "PhysicsWorld.h"

using namespace std;

namespace CGPhysicsEngine
{

PhysicsWorld::PhysicsWorld(void)
{
}


PhysicsWorld::~PhysicsWorld(void)
{
}

void PhysicsWorld::AddObject(BoundingVolume * obj)
{
	_world.push_back(obj);
}

void PhysicsWorld::RemoveObject(BoundingVolume * obj)
{
	for (list<BoundingVolume *>::iterator it = _world.begin() ; it != _world.end(); it++ )
	{
		if(obj == *it) 
		{
			_world.erase(it);
			break;
		}
	}
}
	
BoundingVolume * PhysicsWorld::Single(bool (*Predicate)(BoundingVolume *))
{
	for (list<BoundingVolume *>::iterator it = _world.begin() ; it != _world.end(); it++ )
	{
		if(Predicate(*it)) 
		{
			return *(it);
		}
	}

	return NULL;
}

}