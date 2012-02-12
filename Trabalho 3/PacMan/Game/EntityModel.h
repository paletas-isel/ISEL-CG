#ifndef _PACMAN_ENTITYMODEL_
#define _PACMAN_ENTITYMODEL_

#include "AnimatedModel.h"

class EntityModel :
	public AnimatedModel
{
protected:
	virtual void DoDrawAnimation(float percentageCompleted) = 0;

public:
	EntityModel(int duration);
	~EntityModel(void);

	virtual void Draw() = 0;
};

#endif