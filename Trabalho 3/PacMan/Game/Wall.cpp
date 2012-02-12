#include "Wall.h"

#include <gl\glut.h>

using namespace cggl;

Wall::Wall(ObjectModel * model, BoardCoordinates& coords) : GameObject(model, coords, false)
{
}


Wall::~Wall(void)
{
}