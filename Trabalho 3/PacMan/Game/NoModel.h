#ifndef _PACMAN_NOMODEL_
#define _PACMAN_NOMODEL_

#include "EntityModel.h"

class NoModel : public EntityModel
{
protected:
	void DoDrawAnimation(float percentageCompleted) { }

public:
	NoModel() : EntityModel(1) {}
	~NoModel(void) {}

	void Draw() { }
};

#endif