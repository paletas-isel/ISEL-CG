#ifndef _PE_BVOLUME_
#define _PE_BVOLUME_

#include "cggl/MathUtils.h"

namespace CGPhysicsEngine
{

class BoundingVolume
{
public:
	BoundingVolume(void);
	~BoundingVolume(void);

	virtual cggl::Vector3 GetCenter() = 0;
};

}

#endif