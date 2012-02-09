#ifndef _PACMAN_GHOST_
#define _PACMAN_GHOST_

#include "entity.h"

class Ghost : public Entity
{
protected:
	void DoDrawEntity();
	void StartWalkingAnimation(int durationInMilis);
public:
	Ghost(void);
	~Ghost(void);
};

#endif