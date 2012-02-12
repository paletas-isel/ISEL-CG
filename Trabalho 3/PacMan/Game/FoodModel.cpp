#include "FoodModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>

FoodModel::FoodModel(void)
{
}

FoodModel::~FoodModel(void)
{
}

void FoodModel::DoDraw()
{
	if(!IsEaten())
	{
		glColor3f(0, 0, 0);
		glutSolidSphere(OBJECT_DIMENSION / (float) 5, FOOD_DETAIL, FOOD_DETAIL);
	}
}