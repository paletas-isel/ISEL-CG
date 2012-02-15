#ifndef _PACMAN_GATE_
#define _PACMAN_GATE_

#include "AnimatedGameObject.h"

class Gate : public AnimatedGameObject
{
private:
	bool isOpened, isChanging;
	void ChangeGateStatus(bool open);

protected:
	void DoUpdate(int deltaTimeMilis);

public:
	Gate(AnimatedObjectModel * model, BoardCoordinates& coords);
	~Gate(void);

	void Open();
	void Close();

	bool IsOpen() { return true; } //Portão avariado
};

#endif