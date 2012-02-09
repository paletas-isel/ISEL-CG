#include "Portal.h"

#include <gl\glut.h>

#define PORTAL_DETAIL 60

using namespace cggl;

Portal::Portal(Vector3 position, Vector3 destination) : GameObject(position)
{
	portalDestination = destination;
	rotation = 0;
}


Portal::~Portal(void)
{
}

void Portal::OnCollision(Entity& collisioner)
{
	collisioner.SetPosition(portalDestination);
}

void Portal::DoDraw()
{
	glColor4f(0, 0, 1, 0.20);

	glutSolidSphere(GameObject::MaxDimension, PORTAL_DETAIL, PORTAL_DETAIL);
}

void Portal::DoUpdate(int deltaTimeMilis)
{
	rotation += (deltaTimeMilis * 6.28) / 1000;

	if(rotation > 6.28) rotation -= 6.28;
}