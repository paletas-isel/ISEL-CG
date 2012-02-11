#ifndef _PACMAN_CHASEAI_
#define _PACMAN_CHASEAI_

#include "AIBehaviour.h"

class ChaseAI : public AIBehaviour
{
public:
	ChaseAI(Entity& target, Board& board);
	~ChaseAI(void);

	void ApplyAI(Entity& to);
};

#endif