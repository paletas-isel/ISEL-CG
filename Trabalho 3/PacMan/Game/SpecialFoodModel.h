#pragma once
#include "foodmodel.h"
class SpecialFoodModel :
	public FoodModel
{
protected:
	void DoDraw();

public:
	SpecialFoodModel(void);
	~SpecialFoodModel(void);
};

