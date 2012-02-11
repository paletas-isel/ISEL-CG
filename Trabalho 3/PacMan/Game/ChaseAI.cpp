#include "ChaseAI.h"

#include "Entity.h"
#include "Board.h"

#include <cggl\MathUtils.h>

using namespace cggl;

ChaseAI::ChaseAI(Entity& target, Board& board) : AIBehaviour(target, board)
{
}


ChaseAI::~ChaseAI(void)
{
}

Direction FindValidDirection(Vector3& ghostPosition, Board& board)
{
	Direction directions = (Direction) 0;
	GameObject * obj;

	BoardCoordinates coords = BoardCoordinates::ConvertWorldToBoardCoordinates(ghostPosition);
	
	BoardCoordinates c1(coords.boardX - 1, coords.boardY);
	if((obj = board.ObjectAt(c1)) == NULL || obj->IsWalkable())
		directions = (Direction) (directions | Left);

	BoardCoordinates c2(coords.boardX + 1, coords.boardY);
	if((obj = board.ObjectAt(c2)) == NULL || obj->IsWalkable())
		directions = (Direction) (directions | Right);

	BoardCoordinates c3(coords.boardX, coords.boardY - 1);
	if((obj = board.ObjectAt(c3)) == NULL || obj->IsWalkable())
		directions = (Direction) (directions | Up);

	BoardCoordinates c4(coords.boardX, coords.boardY + 1);
	if((obj = board.ObjectAt(c4)) == NULL || obj->IsWalkable())
		directions = (Direction) (directions | Down);

	return directions;
}

Direction FindPacmanDirection(Vector3& pacmanPosition, Vector3& ghostPosition)
{	
	Direction toRet;
	Vector3 pacManDirection = pacmanPosition - ghostPosition;
		
	if(pacManDirection.x <= 0 && pacManDirection.z <= 0)
	{
		if(pacManDirection.x >= pacManDirection.z)
			toRet = Up;
		else 
			toRet = Left;
	}
	else if(pacManDirection.x >= 0 && pacManDirection.z >= 0)
	{
		if(pacManDirection.x <= pacManDirection.z)
			toRet = Down;
		else 
			toRet = Right;
	}
	else if(pacManDirection.x <= 0 && pacManDirection.z >= 0)
	{
		if(abs(pacManDirection.x) >= pacManDirection.z)
			toRet = Left;
		else 
			toRet = Down;
	}
	else 
	{
		if(pacManDirection.x >= abs(pacManDirection.z))
			toRet = Up;
		else 
			toRet = Right;
	}

	return toRet;
}

void ChaseAI::ApplyAI(Entity& character)
{
	static Direction lastDirection;

	Direction pacManDirection = FindPacmanDirection(GetTarget().GetPosition(), character.GetPosition());	
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