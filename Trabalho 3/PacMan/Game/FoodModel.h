#ifndef _PACMAN_FOODMODEL_
#define _PACMAN_FOODMODEL_

#include "objectmodel.h"
class FoodModel :
	public ObjectModel
{
protected:
	virtual void DoDraw();

public:
	FoodModel(void);
	~FoodModel(void);
};

#endif