#define _USE_MATH_DEFINES

#include "BaseBall.h"
#include <gl\glut.h>
#include <math.h>

using namespace cggl;

#define FALLING_SPEED 1 //Meters Per Second
#define MAX_TIME_BOUNCING 20 //In Seconds
#define BOUNCING_PSECOND 1
#define BOUNCING_ATENUATION 0.5

BaseBall::BaseBall(Vector3 position, int radius)
{
	_position = position;
	_radius = radius;
}


BaseBall::~BaseBall(void)
{
}

int BaseBall::GetRadius()
{
	return _radius;
}

Vector3 BaseBall::GetPosition()
{
	return _position;
}

void BaseBall::SetVelocity(Vector3 velocity)
{
	_velocityVector = velocity;
}

Vector3 BaseBall::GetVelocity()
{
	return _velocityVector;
}

void BaseBall::SetDirection(Direction direction)
{
	_direction = direction;
}

Direction BaseBall::GetDirection()
{
	return _direction;
}


void BaseBall::Draw()
{
	Object::Draw();
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glTranslatef(0, _radius, 0);

		glColor3f(0, 1, 0);
		gluSphere(gluNewQuadric(), _radius, 30, 30);

	glPopMatrix();

	glDisable(GL_LIGHTING);
}

inline bool BaseBall::IsInAir()
{
	return _position.y > 0;
}

void BaseBall::Update(int deltaTimeMilis)
{
	Object::Update(deltaTimeMilis);

	static bool isBouncing = true;
	static float startingHeight = _position.y;
	static double elapsedTime = 0;
	
	if(isBouncing)
	{
		_position.y = startingHeight * abs(cos(((double) BOUNCING_PSECOND / 2) * elapsedTime * 2 * PI)) / exp(BOUNCING_ATENUATION * elapsedTime);
		elapsedTime += ((double) deltaTimeMilis / 1000);
	}

	
}