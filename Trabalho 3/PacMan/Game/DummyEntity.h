#ifndef _PACMAN_DUMMYENTITY_
#define _PACMAN_DUMMYENTITY_

#include "Entity.h"

class DummyEntity : public Entity
{
protected:
	void DoDrawEntity() {}
	void DoDrawWalkingAnimation(int deltaTimeMilis) {}
	void DoUpdate(int deltaTimeMilis) {}
public:
	DummyEntity(cggl::Vector3& position);
	~DummyEntity(void);
};

#endif