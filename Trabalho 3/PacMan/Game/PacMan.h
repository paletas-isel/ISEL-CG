#ifndef _PACMAN_PAC_
#define _PACMAN_PAC_

#include "entity.h"

class PacMan : public Entity
{
private:
	int eatenFoodCount;

protected:
	void DoDrawEntity();
	void StartWalkingAnimation(int durationInMilis);
public:
	PacMan(void);
	~PacMan(void);

	void EatFood() { eatenFoodCount++; }
	int GetFoodEaten() { return eatenFoodCount; }
};

#endif