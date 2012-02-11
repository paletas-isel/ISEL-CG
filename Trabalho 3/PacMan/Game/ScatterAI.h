#ifndef _PACMAN_SCATTERAI_
#define _PACMAN_SCATTERAI_

#include "AIBehaviour.h"
#include "Gate.h"
#include "BoardCoordinates.h"

class ScatterAI : public AIBehaviour
{
private:
	Gate * FindGate(BoardCoordinates& startPosition);

public:
	ScatterAI(Entity& target, Board& board);
	~ScatterAI(void);

	void ApplyAI(Entity& to);
};

#endif