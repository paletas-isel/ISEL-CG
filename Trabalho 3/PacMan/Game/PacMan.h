#ifndef _PACMAN_PAC_
#define _PACMAN_PAC_

#include "entity.h"

class Ghost;

class PacMan : public Entity
{
private:
	int eatenFoodCount;
	int lifes;

protected:
	void DoDrawEntity();
	void DoDrawWalkingAnimation(int deltaTimeMilis);
	void DoUpdate(int deltaTimeMilis);

public:
	PacMan(void);
	~PacMan(void);

	void EatFood() { eatenFoodCount++; }
	int GetFoodEaten() { return eatenFoodCount; }

	int GetLifes() { return lifes; }
	void RemoveLife() { lifes--; }
	void AddLife() { lifes++; }

	void OnCollision(Ghost ghost);
};

#endif