#include "Food.h"
#include "PacMan.h"
#include "FoodEffect.h"

#include <gl\glut.h>

using namespace cggl;

Food::Food(ObjectModel * model, BoardCoordinates coords) : GameObject(model, coords)
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

void Food::Draw()
{
	if(HasBeenEaten()) return;
	GameObject::Draw();
}