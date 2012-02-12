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
	Direction alternativeDirection;
	Direction pacManDirection = FindTargetDirection(GetTarget().GetPosition(), character.GetPosition(), &alternativeDirection);	
	Direction canMove = FindValidDirection(character.GetPosition(), GetBoard());
	
	Direction shouldMove = (Direction) 0;

	if(IsDirectionPresent(pacManDirection, Up) && IsDirectionPresent(canMove, Up) && lastDirection != Down)
	{
		canMove = (Direction)(canMove & ~Up);
		lastDirection = Up;
		character.MoveUp();
		return;
	}
	
	if(IsDirectionPresent(pacManDirection, Down) && IsDirectionPresent(canMove, Down) && lastDirection != Up)
	{
		canMove = (Direction)(canMove & ~Down);
		lastDirection = Down;
		character.MoveDown();
		return;
	}
	
	if(IsDirectionPresent(pacManDirection, Left) && IsDirectionPresent(canMove, Left) && lastDirection != Right)
	{		
		canMove = (Direction)(canMove & ~Left);
		lastDirection = Left;
		character.MoveLeft();
		return;
	}
	
	if(IsDirectionPresent(pacManDirection, Right) && IsDirectionPresent(canMove, Right) && lastDirection != Left)
	{
		canMove = (Direction)(canMove & ~Right);
		lastDirection = Right;
		character.MoveRight();
		return;
	}

	if(lastDirection != OpposingDirection(alternativeDirection) && IsDirectionPresent(canMove, alternativeDirection))
	{
		shouldMove = alternativeDirection;
	}
	else
	{
		canMove = (Direction)(canMove & ~OpposingDirection(lastDirection));
	}

	if(shouldMove == 0) shouldMove = canMove;
	lastDirection = shouldMove;
	switch(shouldMove)
	{
		case Up : character.MoveUp(); break;
		case Down : character.MoveDown(); break;
		case Left : character.MoveLeft(); break;
		case Right : character.MoveRight(); break;
	}
}
