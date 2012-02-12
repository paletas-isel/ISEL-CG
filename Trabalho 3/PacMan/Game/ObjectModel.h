#ifndef _PACMAN_OBJMODEL_
#define _PACMAN_OBJMODEL_

#include "model.h"
class ObjectModel :
	public Model
{
protected:
	virtual void DoDraw() = 0;

public:
	ObjectModel(void);
	~ObjectModel(void);

	void Draw();
};

#endif