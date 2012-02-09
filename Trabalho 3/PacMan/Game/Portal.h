#ifndef _PACMAN_PORTAL_
#define _PACMAN_PORTAL_

#include "GameObject.h"

class Portal : public GameObject
{
private:
	cggl::Vector3 portalDestination;
	float rotation;

protected:
	void OnCollision(Entity& collisioner);

	void DoDraw();
	void DoUpdate(int deltaTimeMilis);

public:
	Portal(cggl::Vector3 position, cggl::Vector3 destination);
	~Portal(void);
};

#endif