#ifndef _SSS_BASESLIME_
#define _SSS_BASESLIME_

#include "cggl\Object.h"
#include "cggl\MathUtils.h"
#include "HalfSphere.h"
#include "BaseBall.h"
#include "physicsengine\SpherePhysicObject.h"

#define SLIME_MASS 20

class BaseSlime : public cggl::Object, public CGPhysicsEngine::SpherePhysicObject
{
private:

#pragma region "Geometry"

	float _red, _green, _blue, _alpha;
	HalfSphere _body;
	cggl::Vector3 * _position;
	int _radius;
	
	void SetColor(float red, float green, float blue, float alpha);
	virtual void SetMaterial();

#pragma endregion

#pragma region "Physics"
	
	short _maxJumpHeight;
	BaseBall * _ball;

	cggl::Vector3 _velocityVector;


	virtual bool IsCollidingWithBall();

#pragma endregion

public:
	BaseSlime(BaseBall * ball, cggl::Vector3 position, int radius, short maxJumpHeight = 2);
	~BaseSlime(void);
		
	void Update(int deltaTimeMilis);
	void Draw();
};

#endif