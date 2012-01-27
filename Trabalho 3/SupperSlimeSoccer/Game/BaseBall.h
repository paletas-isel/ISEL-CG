#ifndef _SSS_BASEBALL_
#define _SSS_BASEBALL_

#include "cggl\Object.h"
#include "cggl\MathUtils.h"

#include "physicsengine\SpherePhysicObject.h"

enum Direction { LEFT=0x1, RIGHT=0x2, UP=0x4, DOWN=0x8 };

#pragma once
class BaseBall : public cggl::Object
{

#pragma region "Geometry"
private:
	int _radius;

public:
	int GetRadius();

	cggl::Vector3 GetPosition() { return _obj.GetPosition(); }

#pragma endregion	

#pragma region "Physics"
private:
	CGPhysicsEngine::SpherePhysicObject _obj;
	
public:
	CGPhysicsEngine::SpherePhysicObject GetPhysicObject() { return _obj; }

	friend class BaseSlime;
#pragma endregion

public:
	BaseBall(cggl::Vector3 position, int radius);
	~BaseBall(void);

	void Draw();
	void Update(int deltaTimeMilis);
};

#endif