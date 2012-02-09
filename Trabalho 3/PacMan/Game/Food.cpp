#include "Food.h"
#include "PacMan.h"
#include "FoodEffect.h"

#include <gl\glut.h>

#define FOOD_DETAIL 60

using namespace cggl;

Food::Food(Vector3 position) : GameObject(position)
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
		glColor3f(1, 1, 0);
		glutSolidSphere(GameObject::MaxDimension / 5, FOOD_DETAIL, FOOD_DETAIL);
	}
}