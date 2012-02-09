#ifndef _PACMAN_WALL_
#define _PACMAN_WALL_

#include "GameObject.h"
#include "Entity.h"

#include <cggl\MathUtils.h>

class Wall : public GameObject
{

protected:
	void DoDraw();

public:
	Wall(cggl::Vector3 position);
	~Wall(void);

};

#endif