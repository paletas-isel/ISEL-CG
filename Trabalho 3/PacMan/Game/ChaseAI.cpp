#include "ChaseAI.h"

#include "Entity.h"
#include "Board.h"

ChaseAI::ChaseAI(Entity& target, Board& board) : AIBehaviour(target, board)
{
}


ChaseAI::~ChaseAI(void)
{
}



void ChaseAI::ApplyAI(Entity& character)
{
	static Direction lastDirection;

	Direction pacManDirection = FindTargetDirection(GetTarget().GetPosition(), character.GetPosition());	
	Direction canMove = FindValidDirection(character.GetPosition(), GetBoard());
	
	if(IsDirectionPresent(pacManDirection, Up) && IsDirectionPresent(canMove, Up) && lastDirection != Down)
	{
		lastDirection = Up;
		character.MoveUp();
	}
	else if(IsDirectionPresent(pacManDirection, Down) && IsDirectionPresent(canMove, Down) && lastDirection != Up)
	{
		lastDirection = Down;
		character.MoveDown();
	}
	else if(IsDirectionPresent(pacManDirection, Left) && IsDirectionPresent(canMove, Left) && lastDirection != Right)
	{
		lastDirection = Left;
		character.MoveLeft();
	}
	else if(IsDirectionPresent(pacManDirection, Right) && IsDirectionPresent(canMove, Right) && lastDirection != Left)
	{
		lastDirection = Right;
		character.MoveRight();
	}
}