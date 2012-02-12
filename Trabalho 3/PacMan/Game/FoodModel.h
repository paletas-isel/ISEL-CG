#ifndef _PACMAN_FOODMODEL_
#define _PACMAN_FOODMODEL_

#include "objectmodel.h"
class FoodModel :
	public ObjectModel
{
private:
	bool isEaten;

protected:
	virtual void DoDraw();

	bool IsEaten() { return isEaten; }

public:
	FoodModel(void);
	~FoodModel(void);

	void SetEaten() { isEaten = true; }
};

#endif