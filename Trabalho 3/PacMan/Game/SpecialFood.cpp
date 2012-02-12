#include "SpecialFood.h"
#include "FoodEffect.h"

#include <gl\glut.h>

using namespace cggl;

SpecialFood::SpecialFood(ObjectModel * model, BoardCoordinates& coords) : Food(model, coords)
{
}


SpecialFood::~SpecialFood(void)
{
}

Effect& SpecialFood::GetEffect()
{
	return *(new FoodEffect(10));
}