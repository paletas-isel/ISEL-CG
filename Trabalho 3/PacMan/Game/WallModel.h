#ifndef _PACMAN_WALLMODEL_
#define _PACMAN_WALLMODEL_

#include "objectmodel.h"

class WallModel : public ObjectModel
{
protected:
	void DoDraw();

public:
	WallModel(void);
	~WallModel(void);
};

#endif