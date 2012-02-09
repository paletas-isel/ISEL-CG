#include "Wall.h"

#include <gl\glut.h>

using namespace cggl;

Wall::Wall(Vector3 position) : GameObject(position, false)
{
}


Wall::~Wall(void)
{
}

void Wall::DoDraw()
{
	glColor3f(1, 0, 0);
	glutSolidCube(GameObject::MaxDimension);
}