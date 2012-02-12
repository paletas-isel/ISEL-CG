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
	void DoUpdate(int deltaTimeMilis);

public:
	Ghost(EntityModel * model, PacMan& pac, Board& board);
	~Ghost(void);
};

#endif