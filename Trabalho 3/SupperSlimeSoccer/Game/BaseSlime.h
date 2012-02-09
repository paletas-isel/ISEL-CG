#ifndef _SSS_BASESLIME_
#define _SSS_BASESLIME_

#include "cggl\Object.h"
#include "cggl\MathUtils.h"
#include "HalfSphere.h"
#include "BaseBall.h"
#include "physicsengine\PhysicEnabledObject.h"

class BaseSlime : public cggl::Object
{
private:

#pragma region "Geometry"

	float _red, _green, _blue, _alpha;
	HalfSphere _body;
	int _radius;

protected:

	void SetColor(float red, float green, float blue, float alpha);

	virtual void SetMaterial();

	cggl::Vector3 GetPosition() { return _obj.GetPosition(); }

#pragma endregion

#pragma region "Physics"
private:
	CGPhysicsEngine::PhysicEnabledObject _obj;

public:
	cggl::Vector3 GetCenter() { return _obj.GetPosition(); }
	CGPhysicsEngine::PhysicEnabledObject GetPhysicObject() { return _obj; }

#pragma endregion

public:
	BaseSlime(cggl::Vector3 position, int radius);
	~BaseSlime(void);
		
	void Update(int deltaTimeMilis);
	void Draw();
};

#endif