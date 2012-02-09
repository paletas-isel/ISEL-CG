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

void PhysicsWorld::AddObject(PhysicEnabledObject * obj)
{
	_world.push_back(obj);
}

void PhysicsWorld::RemoveObject(PhysicEnabledObject * obj)
{
	for (list<PhysicEnabledObject *>::iterator it = _world.begin() ; it != _world.end(); it++ )
	{
		if(obj == *it) 
		{
			_world.erase(it);
			break;
		}
	}
}
	
PhysicEnabledObject * PhysicsWorld::Single(bool (*Predicate)(PhysicEnabledObject *))
{
	for (list<PhysicEnabledObject *>::iterator it = _world.begin() ; it != _world.end(); it++ )
	{
		if(Predicate(*it)) 
		{
			return *(it);
		}
	}

	return NULL;
}

}