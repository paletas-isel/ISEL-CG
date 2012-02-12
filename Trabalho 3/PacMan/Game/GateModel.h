#ifndef _PACMAN_GATEMODEL_
#define _PACMAN_GATEMODEL_

#include "AnimatedObjectModel.h"

class GateModel :
	public AnimatedObjectModel
{
private:
	bool isOpeningAnimation;

protected:
	void DoDrawAnimation(float percentageComplete);	
	void DoDraw();

public:
	GateModel(int duration);
	~GateModel(void);

	void SetGateStatus(bool isOpen) { isOpeningAnimation = !isOpen; }
};

#endif