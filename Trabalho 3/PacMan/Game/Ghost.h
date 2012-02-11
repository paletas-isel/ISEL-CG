#ifndef _PACMAN_GHOST_
#define _PACMAN_GHOST_

#include "entity.h"
#include "PacMan.h"

class Ghost : public Entity
{
private:
	PacMan& entityPac;

protected:
	void DoDrawEntity();
	void DoDrawWalkingAnimation(int deltaTimeMilis);
	void DoUpdate(int deltaTimeMilis);

public:
	Ghost(PacMan& pac);
	~Ghost(void);
};

#endif