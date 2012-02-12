#include "GhostModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>

GhostModel::GhostModel(int animationDuration) : EntityModel(animationDuration)
{
}

GhostModel::~GhostModel(void)
{
}

void GhostModel::Draw()
{
	glColor3f(1, 0, 0);
	glRotatef(3.14f, 1, 0, 0);
	glutSolidCone(OBJECT_DIMENSION / 2.0f, OBJECT_DIMENSION, 10, 10); 
}
	
void GhostModel::DoDrawAnimation(float percentageCompleted)
{
	Draw();
}