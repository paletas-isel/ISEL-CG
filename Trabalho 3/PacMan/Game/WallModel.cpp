#include "WallModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>


WallModel::WallModel(void)
{
}


WallModel::~WallModel(void)
{
}

void WallModel::DoDraw()
{
	glColor3f(1, 0, 0);
	glutSolidCube(OBJECT_DIMENSION);
}
