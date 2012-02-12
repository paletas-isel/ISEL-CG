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
	ChangeGateStatus(true);
}

void Gate::Close()
{
	ChangeGateStatus(false);
}