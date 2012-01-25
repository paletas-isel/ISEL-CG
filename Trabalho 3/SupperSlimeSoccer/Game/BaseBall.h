#ifndef _SSS_BASEBALL_
#define _SSS_BASEBALL_

#include "cggl\Object.h"
#include "cggl\MathUtils.h"

enum Direction { LEFT=0x1, RIGHT=0x2, UP=0x4, DOWN=0x8 };

#pragma once
class BaseBall : public cggl::Object
{
private:

#pragma region "Geometry"

	cggl::Vector3 _position;
	int _radius;

	cggl::Vector3 GetPosition();
	int GetRadius();

#pragma endregion	

#pragma region "Physics"
	
	cggl::Vector3 _velocityVector;
	Direction _direction;

	inline virtual bool IsInAir();
	
	void SetVelocity(cggl::Vector3 velocity);
	cggl::Vector3 GetVelocity();
	void SetDirection(Direction direction);
	Direction GetDirection();

	friend class BaseSlime;
#pragma endregion

public:
	BaseBall(cggl::Vector3 position, int radius);
	~BaseBall(void);

	void Draw();
	void Update(int deltaTimeMilis);
};

#endif