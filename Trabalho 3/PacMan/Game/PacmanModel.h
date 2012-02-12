#ifndef _PACMAN_PACMODEL_
#define _PACMAN_PACMODEL_

#include "EntityModel.h"

class PacmanModel : public EntityModel
{
protected:
	void DoDrawAnimation(float percentageCompleted);

public:
	PacmanModel(int animationDuration);
	~PacmanModel(void);

	void Draw();
};

#endif