#include "AIBehaviour.h"

#include "Entity.h"
#include "Board.h"

using namespace cggl;

AIBehaviour::AIBehaviour(Entity& target, Board& board) : board(board), target(target)
{
}


AIBehaviour::~AIBehaviour(void)
{
}

bool AIBehaviour::IsDirectionPresent(Direction value, Direction wanted)
{
	return (value & wanted) != 0;
}

Direction AIBehaviour::FindValidDirection(Vector3& ghostPosition, Board& board)
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

Direction AIBehaviour::FindTargetDirection(Vector3& targetPosition, Vector3& ghostPosition, Direction * alternative)
{	
	Direction toRet;
	Vector3 targetDirection = targetPosition - ghostPosition;
		
	if(targetDirection.x <= 0 && targetDirection.z <= 0)
	{
		if(targetDirection.x >= targetDirection.z)
		{
			toRet = Up;
			*alternative = Left;
		}
		else 
		{
			toRet = Left;
			*alternative = Up;
		}
	}
	else if(targetDirection.x >= 0 && targetDirection.z >= 0)
	{
		if(targetDirection.x <= targetDirection.z)
		{
			toRet = Down;
			*alternative = Right;
		}
		else 
		{
			toRet = Right;
			*alternative = Down;
		}
	}
	else if(targetDirection.x <= 0 && targetDirection.z >= 0)
	{
		if(abs(targetDirection.x) >= targetDirection.z)
		{
			toRet = Left;
			*alternative = Down;
		}
		else 
		{
			toRet = Down;
			*alternative = Left;
		}
	}
	else 
	{
		if(targetDirection.x >= abs(targetDirection.z))
		{
			toRet = Up;
			*alternative = Right;
		}
		else 
		{
			toRet = Right;
			*alternative = Up;
		}
	}

	return toRet;
}

Direction AIBehaviour::OpposingDirection(Direction wanted)
{
	if((wanted & 2) != 0 || (wanted & 8) != 0)
		return (Direction) (wanted >> 1);
	return (Direction) (wanted << 1);
}