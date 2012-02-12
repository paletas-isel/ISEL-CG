#ifndef _PACMAN_GATE_
#define _PACMAN_GATE_

#include "AnimatedGameObject.h"

class Gate : public AnimatedGameObject
{
private:
	bool isOpened;
	void ChangeGateStatus(bool open);

public:
	Gate(AnimatedObjectModel * model, BoardCoordinates& coords);
	~Gate(void);

	void Open();
	void Close();

	bool IsOpen() { return isOpened; }
};

#endif