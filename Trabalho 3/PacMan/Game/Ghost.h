#ifndef _PACMAN_GHOST_
#define _PACMAN_GHOST_

#include "entity.h"
#include "PacMan.h"

#include "AIBehaviour.h"

class Ghost : public Entity
{
private:
	PacMan& entityPac;

	AIBehaviour * scatterAi, * chaseAi;

protected:
	void DoDrawEntity();
	void DoDrawWalkingAnimation(int deltaTimeMilis);
	void DoUpdate(int deltaTimeMilis);

public:
	Ghost(PacMan& pac, Board& board);
	~Ghost(void);
};

#endif