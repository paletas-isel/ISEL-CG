#include "Gate.h"

#include <gl\glut.h>

using namespace cggl;

#define OPEN true
#define CLOSED false

Gate::Gate(AnimatedObjectModel * model, BoardCoordinates& coords) : AnimatedGameObject(model, coords, false)
{
	isOpened = false;	
}


Gate::~Gate(void)
{
}

void Gate::ChangeGateStatus(bool open)
{
	isOpened = open;
	SetWalkable(isOpened);
	
}

void Gate::Open()
{
	isChanging = true;
	ChangeGateStatus(true);
}

void Gate::Close()
{
	isChanging = true;
	ChangeGateStatus(false);
}
	
void Gate::DoUpdate(int deltaTimeMilis)
{
	if(isChanging)
		GetAnimatedModel()->AddAnimationTime(deltaTimeMilis);

	if(GetAnimatedModel()->HasAnimationComplete()) isChanging = false;
}