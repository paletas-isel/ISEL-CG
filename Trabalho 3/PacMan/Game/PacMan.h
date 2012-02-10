#ifndef _PACMAN_PAC_
#define _PACMAN_PAC_

#include "entity.h"

class PacMan : public Entity
{
private:
	int eatenFoodCount;

protected:
	void DoDrawEntity();
	void DoDrawWalkingAnimation(int deltaTimeMilis);
	void DoUpdate(int deltaTimeMilis);

public:
	PacMan(void);
	~PacMan(void);

	void EatFood() { eatenFoodCount++; }
	int GetFoodEaten() { return eatenFoodCount; }
};

#endif