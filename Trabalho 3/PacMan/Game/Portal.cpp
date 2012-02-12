#include "Portal.h"

#include <gl\glut.h>

#define PORTAL_DETAIL 20

using namespace cggl;

Portal::Portal(ObjectModel& model, BoardCoordinates& coords) : GameObject(model, coords), portalDestination(-1, -1)
{
	rotation = 0;
}


Portal::~Portal(void)
{
}

void Portal::OnCollision(Entity& collisioner)
{
	collisioner.SetPosition(BoardCoordinates::ConvertBoardToWorldCoordinates(portalDestination));

}

void Portal::DoDraw()
{
	glColor4f(0, 0, 1, 0.20);

	glutSolidSphere(OBJECT_DIMENSION / 2, PORTAL_DETAIL, PORTAL_DETAIL);
}

void Portal::DoUpdate(int deltaTimeMilis)
{
	rotation += (deltaTimeMilis * 6.28) / 1000;

	if(rotation > 6.28) rotation -= 6.28;
}