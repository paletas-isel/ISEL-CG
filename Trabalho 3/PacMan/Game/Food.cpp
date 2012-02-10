#include "Food.h"
#include "PacMan.h"
#include "FoodEffect.h"

#include <gl\glut.h>

using namespace cggl;

Food::Food(BoardCoordinates coords) : GameObject(coords)
{
	hasBeenEaten = false;
}

Food::~Food(void)
{
}
	
Effect& Food::GetEffect()
{
	return *(new FoodEffect(1));
}

void Food::OnCollision(Entity& collisioner)
{
	Effect& effect = GetEffect();

	if(!HasBeenEaten() && collisioner.BelongsToType(effect.GetTargetTypes()))
	{
		effect.ApplyEffect(collisioner);
		SetEaten();
	}
}

void Food::DoDraw()
{
	if(!HasBeenEaten())
	{
		glColor3f(0, 0, 0);
		glutSolidSphere(OBJECT_DIMENSION / (float) 5, FOOD_DETAIL, FOOD_DETAIL);
	}
}