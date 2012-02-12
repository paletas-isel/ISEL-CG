#include "Wall.h"

#include <gl\glut.h>

using namespace cggl;

Wall::Wall(ObjectModel& model, BoardCoordinates& coords) : GameObject(model, coords, false)
{
}


Wall::~Wall(void)
{
}

void Wall::DoDraw()
{
	glColor3f(1, 0, 0);
	glutSolidCube(OBJECT_DIMENSION);
}