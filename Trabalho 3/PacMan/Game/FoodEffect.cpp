#include "FoodEffect.h"

#include "PacMan.h"

FoodEffect::FoodEffect(int foodAmmount) : Effect(PacmanEntity)
{
	FoodEffect::foodAmmount = foodAmmount;
}


FoodEffect::~FoodEffect(void)
{
}

void FoodEffect::ApplyEffect(Entity& entity)
{
	PacMan& pac = (PacMan&) entity;

	for(int ix = 0; ix < foodAmmount; ++ix)
	{
		pac.EatFood();
	}
}