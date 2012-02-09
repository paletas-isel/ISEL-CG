#ifndef _PACMAN_FOODEFFECT_
#define _PACMAN_FOODEFFECT_

#include "Effect.h"
#include "PacMan.h"

class FoodEffect : public Effect
{
private:
	int foodAmmount;

public:
	FoodEffect(int foodAmmount);
	~FoodEffect(void);

	void ApplyEffect(Entity& entity);
};

#endif