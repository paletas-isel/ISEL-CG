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
	glPushMatrix();

		glColor3f(1, 1, 0);
		glutSolidSphere(OBJECT_DIMENSION / 2.0f, PACMAN_DETAIL, PACMAN_DETAIL); 
		glColor3f(1, 0, 0);
		glTranslatef(OBJECT_DIMENSION / 2.0f - OBJECT_DIMENSION / 10.0f, OBJECT_DIMENSION / 3.0f, 0);
		glutSolidSphere(OBJECT_DIMENSION / 10.0f, PACMAN_DETAIL, PACMAN_DETAIL);
		glTranslatef(0, OBJECT_DIMENSION / 3.0f, OBJECT_DIMENSION / 2.0f - OBJECT_DIMENSION / 10.0f);
		glutSolidSphere(OBJECT_DIMENSION / 10.0f, PACMAN_DETAIL, PACMAN_DETAIL);

	glPopMatrix();
}
	
void PacmanModel::DoDrawAnimation(float percentageCompleted)
{
	Draw();
}