#ifndef _PACMAN_GHOSTMODEL_
#define _PACMAN_GHOSTMODEL_

#include "EntityModel.h"

class GhostModel : public EntityModel
{
protected:
	void DoDrawAnimation(float percentageCompleted);

public:
	GhostModel(int animationDuration);
	~GhostModel(void);

	void Draw();
};

#endif