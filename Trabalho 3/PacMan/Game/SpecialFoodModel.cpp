#include "SpecialFoodModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>


SpecialFoodModel::SpecialFoodModel(void)
{
}


SpecialFoodModel::~SpecialFoodModel(void)
{
}

void SpecialFoodModel::DoDraw()
{
	if(!IsEaten())
	{
		glColor3f(0.0706, 0, 0.8274);
		glutSolidSphere(OBJECT_DIMENSION / (float) 3, FOOD_DETAIL, FOOD_DETAIL);
	}
}