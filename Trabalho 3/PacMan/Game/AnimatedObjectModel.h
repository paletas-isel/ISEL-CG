#ifndef _PACMAN_ANIMOBJMODEL_
#define _PACMAN_ANIMOBJMODEL_

#include "objectmodel.h"
#include "AnimatedModel.h"

class AnimatedObjectModel :
	public ObjectModel, public AnimatedModel
{
protected:
	virtual void DoDrawAnimation(float percentageCompleted) = 0;
	virtual void DoDraw() = 0;

public:
	AnimatedObjectModel(int animationDuration);
	~AnimatedObjectModel(void);

	void Draw();
};

#endif