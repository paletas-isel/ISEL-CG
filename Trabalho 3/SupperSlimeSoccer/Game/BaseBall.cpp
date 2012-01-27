#define _USE_MATH_DEFINES

#include "BaseBall.h"
#include <gl\glut.h>
#include <math.h>

using namespace cggl;

#define FALLING_SPEED 1 //Meters Per Second
#define MAX_TIME_BOUNCING 20 //In Seconds
#define BOUNCING_PSECOND 1
#define BOUNCING_ATENUATION 0.5
#define BALL_MASS 20

BaseBall::BaseBall(Vector3 position, int radius) : _obj(position, BALL_MASS, radius, 5)
{
	_radius = radius;
}


BaseBall::~BaseBall(void)
{
}

void BaseBall::Draw()
{
	Object::Draw();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glPushMatrix();

		glTranslatef(GetPosition().x, GetPosition().y, GetPosition().z);

		glTranslatef(0, _radius, 0);

		glColor3f(0, 1, 0);
		gluSphere(gluNewQuadric(), _radius, 30, 30);

	glPopMatrix();

	glDisable(GL_LIGHTING);
}

void BaseBall::Update(int deltaTimeMilis)
{
	Object::Update(deltaTimeMilis);

	

	
}