#include "AIBehaviour.h"

#include "Entity.h"
#include "Board.h"

AIBehaviour::AIBehaviour(Entity& target, Board& board) : board(board), target(target)
{
}


AIBehaviour::~AIBehaviour(void)
{
}

bool IsDirectionPresent(Direction value, Direction wanted)
{
	return (value & wanted) != 0;
}