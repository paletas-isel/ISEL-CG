#include "Wall.h"

#include <gl\glut.h>

using namespace cggl;

Wall::Wall(BoardCoordinates& coords) : GameObject(coords, false)
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