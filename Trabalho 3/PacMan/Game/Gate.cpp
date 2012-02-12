#include "Gate.h"

#include <gl\glut.h>

using namespace cggl;

#define OPEN true
#define CLOSED false

Gate::Gate(AnimatedObjectModel& model, BoardCoordinates& coords) : AnimatedGameObject(model, coords, false)
{
	isOpened = false;	

	gateMaxHeight = OBJECT_DIMENSION;
	
	animationStarted = false;
	animationTime = 0;
}


Gate::~Gate(void)
{
}

void drawGate(int size)
{
	glScalef(1, 1, 0.3);

	glutSolidCube(size);
}

void Gate::DoDraw()
{
	if(!isOpened && !animationStarted)
	{
		drawGate(gateMaxHeight);
	}
	else if(animationStarted)
	{		
		int sizeDif = gateMaxHeight - gateHeight;

		glPushMatrix();
			glTranslatef(gateHeight / 2 + sizeDif * -1, 0, 0);
			drawGate(gateHeight);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(gateHeight / 2 + sizeDif, 0, 0);
			drawGate(gateHeight);
		glPopMatrix();
	}
}

void Gate::DoUpdate(int deltaTimeMilis)
{
	if(animationStarted)		
	{
		animationTime += deltaTimeMilis;
	
		if(isOpened)
		{
			gateHeight = gateMaxHeight * (animationTime / (float) animationDuration);
			if(gateHeight >= gateMaxHeight)
			{
				ChangeGateStatus(CLOSED);
				gateHeight = gateMaxHeight;
				animationStarted = false;
			}
		}
		else
		{
			gateHeight = gateMaxHeight - (gateMaxHeight * (animationTime / (float) animationDuration));
			if(gateHeight <= 0)
			{
				gateHeight = 0;
				animationStarted = false;
				ChangeGateStatus(OPEN);
			}
		}
	}
}

void Gate::ChangeGateStatus(bool open)
{
	isOpened = open;
	SetWalkable(isOpened);
}

void Gate::Open()
{
	animationStarted = true;
	animationTime = 0;
}

void Gate::Close()
{
	animationStarted = true;
	animationTime = 0;
	SetWalkable(false);
}