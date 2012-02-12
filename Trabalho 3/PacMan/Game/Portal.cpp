#include "Portal.h"

#include <gl\glut.h>

using namespace cggl;

Portal::Portal(ObjectModel * model, BoardCoordinates& coords) : GameObject(model, coords), portalDestination(-1, -1)
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