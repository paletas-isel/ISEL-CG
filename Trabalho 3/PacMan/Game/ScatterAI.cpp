#include "ScatterAI.h"

#include "Board.h"

ScatterAI::ScatterAI(Entity& target, Board& board) : AIBehaviour(target, board)
{
}


ScatterAI::~ScatterAI(void)
{
}

void ScatterAI::ApplyAI(Entity& character)
{
	static Gate * gate = dynamic_cast<Gate *>(GetBoard().ObjectOfType(GhostGate));
		
	Direction gateDirection = FindTargetDirection(GetTarget().GetPosition(), gate->GetPosition());	
	Direction canMove = FindValidDirection(GetTarget().GetPosition(), GetBoard());

	if(IsDirectionPresent(gateDirection, Up) && IsDirectionPresent(canMove, Up))
	{
		character.MoveUp();
	}
	else if(IsDirectionPresent(gateDirection, Down) && IsDirectionPresent(canMove, Down))
	{
		character.MoveDown();
	}
	else if(IsDirectionPresent(gateDirection, Left) && IsDirectionPresent(canMove, Left))
	{
		character.MoveLeft();
	}
	else if(IsDirectionPresent(gateDirection, Right) && IsDirectionPresent(canMove, Right))
	{
		character.MoveRight();
	}
}