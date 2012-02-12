#ifndef _PACMAN_WALL_
#define _PACMAN_WALL_

#include "GameObject.h"
#include "Entity.h"

#include <cggl\MathUtils.h>

class Wall : public GameObject
{
public:
	Wall(ObjectModel * model, BoardCoordinates& coords);
	~Wall(void);

};

#endif