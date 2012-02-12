#include "PortalModel.h"
#include "GameStaticSettings.h"

#include <gl\glut.h>


PortalModel::PortalModel(void)
{
}


PortalModel::~PortalModel(void)
{
}


void PortalModel::DoDraw()
{
	glColor4f(0, 0, 1, 0.20);

	glutSolidSphere(OBJECT_DIMENSION / 2, PORTAL_DETAIL, PORTAL_DETAIL);
}