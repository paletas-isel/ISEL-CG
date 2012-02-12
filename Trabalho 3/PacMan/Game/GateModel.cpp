#include "GateModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>

GateModel::GateModel(int duration) : AnimatedObjectModel(duration)
{
}

GateModel::~GateModel(void)
{
}

void drawGate(int size)
{
	glScalef(1, 1, 0.3);

	glutSolidCube(size);
}

void GateModel::DoDraw()
{
	drawGate(OBJECT_DIMENSION);
}

void GateModel::DoDrawAnimation(float percentageComplete)
{
	int gateHeight = OBJECT_DIMENSION * (percentageComplete / 100);
	int sizeDif = OBJECT_DIMENSION - gateHeight;

	glPushMatrix();
		glTranslatef(gateHeight / 2 + sizeDif * -1, 0, 0);
		drawGate(gateHeight);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(gateHeight / 2 + sizeDif, 0, 0);
		drawGate(gateHeight);
	glPopMatrix();
}