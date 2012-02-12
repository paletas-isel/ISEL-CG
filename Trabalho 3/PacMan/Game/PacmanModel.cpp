#include "PacmanModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>


PacmanModel::PacmanModel(int animationDuration) : EntityModel(animationDuration)
{
}

PacmanModel::~PacmanModel(void)
{
}

void PacmanModel::Draw()
{
	glColor3f(1, 1, 0);
	glutSolidCone(OBJECT_DIMENSION / 2.0f, OBJECT_DIMENSION, 10, 10); 
}
	
void PacmanModel::DoDrawAnimation(float percentageCompleted)
{
	Draw();
}