#ifndef _PACMAN_PORTAL_
#define _PACMAN_PORTAL_

#include "GameObject.h"
#include "Board.h"

class Portal : public GameObject
{
private:
	BoardCoordinates portalDestination;
	float rotation;

protected:
	void OnCollision(Entity& collisioner);

	void DoDraw();
	void DoUpdate(int deltaTimeMilis);

public:
	Portal(BoardCoordinates& coords);
	~Portal(void);

	void SetDestination(BoardCoordinates& destination) { portalDestination = destination; }
	BoardCoordinates& GetDestination() { return portalDestination; }
};

#endif