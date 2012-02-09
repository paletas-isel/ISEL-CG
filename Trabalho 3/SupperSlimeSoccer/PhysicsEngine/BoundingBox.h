#ifndef _PE_BBOX_
#define _PE_BBOX_

#include "cggl/MathUtils.h"

namespace CGPhysicsEngine
{

struct HalfWidth
{
	float x;
	float y;
	float z;

	HalfWidth(float xx = 0, float yy = 0, float zz = 0) : x(xx), y(yy), z(zz) { }

};

class BoundingBox
{
private:
	HalfWidth _halfWidth;
	cggl::Vector3 _center;

public:
	BoundingBox(cggl::Vector3 center, cggl::Vector3 dimensions);
	~BoundingBox(void);

	HalfWidth GetHalfWidth() { return _halfWidth; }
	cggl::Vector3 GetCenter() { return _center; }
};

}

#endif
