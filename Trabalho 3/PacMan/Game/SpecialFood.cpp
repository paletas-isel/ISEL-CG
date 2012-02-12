#include "SpecialFood.h"

#include <gl\glut.h>

using namespace cggl;

SpecialFood::SpecialFood(ObjectModel& model, BoardCoordinates& coords) : Food(model, coords)
{
}


SpecialFood::~SpecialFood(void)
{
}

void SpecialFood::DoDraw()
{
	if(!HasBeenEaten())
	{
		glColor3f(0.0706, 0, 0.8274);
		glutSolidSphere(OBJECT_DIMENSION / (float) 3, FOOD_DETAIL, FOOD_DETAIL);
	}
}