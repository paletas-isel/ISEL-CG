#ifndef _PACMAN_AI_
#define _PACMAN_AI_

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

public:
	AIBehaviour(Entity& target, Board& board);
	~AIBehaviour(void);
	
	virtual void ApplyAI(Entity& to) = 0;
};

bool IsDirectionPresent(Direction value, Direction wanted);

#endif