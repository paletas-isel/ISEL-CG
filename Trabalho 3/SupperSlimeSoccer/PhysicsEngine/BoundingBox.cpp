#include "BoundingBox.h"
#include <math.h>

using namespace cggl;

namespace CGPhysicsEngine
{

BoundingBox::BoundingBox(Vector3 center, Vector3 dimensions)
{
	_center = center;
	_halfWidth = HalfWidth ( dimensions.x / 2, dimensions.y / 2, dimensions.z / 2 );
}


BoundingBox::~BoundingBox(void)
{
}

}