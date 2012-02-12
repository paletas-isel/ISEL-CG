#ifndef _PACMAN_PAC_
#define _PACMAN_PAC_

#include "entity.h"

class Ghost;

class PacMan : public Entity
{
private:
	int eatenFoodCount;
	int lifes;
	cggl::Vector3 initialPosition;
	bool hasInitial;

protected:
	void DoDrawEntity();
	void DoDrawWalkingAnimation(int deltaTimeMilis);
	void DoUpdate(int deltaTimeMilis);

public:
	PacMan(EntityModel * model);
	~PacMan(void);

	void EatFood() { eatenFoodCount++; }
	int GetFoodEaten() { return eatenFoodCount; }

	int GetLifes() { return lifes; }
	void RemoveLife() { lifes--; }
	void AddLife() { lifes++; }

	void OnCollision(Entity& ghost);

	void SetPosition(cggl::Vector3 position);
};

#endif