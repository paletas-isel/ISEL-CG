#ifndef _PACMAN_AI_
#define _PACMAN_AI_

#include <cggl\MathUtils.h>

class Entity;
class Board;

enum Direction
{
	Up = 1,
	Down = 2,
	Left = 4,
	Right = 8
};

class AIBehaviour
{
private:
	Entity& target;
	Board& board;

protected:
	Entity& GetTarget() { return target; }
	Board& GetBoard() { return board; }

	bool IsDirectionPresent(Direction value, Direction wanted);
	Direction AIBehaviour::FindValidDirection(cggl::Vector3& ghostPosition, Board& board);
	Direction AIBehaviour::FindTargetDirection(cggl::Vector3& targetPosition, cggl::Vector3& ghostPosition);

public:
	AIBehaviour(Entity& target, Board& board);
	~AIBehaviour(void);
	
	virtual void ApplyAI(Entity& to) = 0;
};


#endif