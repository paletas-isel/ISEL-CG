#ifndef _PACMAN_GATE_
#define _PACMAN_GATE_

#include "AnimatedGameObject.h"

class Gate : public AnimatedGameObject
{
private:
	bool isOpened, animationStarted;
	float gateHeight, gateMaxHeight;

	int animationTime;
	static const int animationDuration = 3000;

	void ChangeGateStatus(bool open);
protected:
	void DoDraw();
	void DoUpdate(int deltaTimeMilis);

public:
	Gate(AnimatedObjectModel& model, BoardCoordinates& coords);
	~Gate(void);

	void Open();
	void Close();

	bool IsOpen() { return isOpened; }
};

#endif