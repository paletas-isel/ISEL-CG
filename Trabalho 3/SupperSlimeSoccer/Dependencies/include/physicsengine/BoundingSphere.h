#ifndef _PE_BSPHERE_
#define _PE_BSPHERE_

#include "cggl\MathUtils.h"
#include "BoundingVolume.h"

namespace CGPhysicsEngine
{

class BoundingSphere : public BoundingVolume
{
private:
	float _radius;

public:
	BoundingSphere(float radius);
	~BoundingSphere(void);

	float GetRadius() { return _radius; }

};

}

#endif