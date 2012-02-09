#ifndef _PACMAN_GAMEOBJ_
#define _PACMAN_GAMEOBJ_

#include <cggl\Object.h>
#include <cggl\MathUtils.h>

#include "Entity.h"

class GameObject : public cggl::Object
{
private: 
	bool isWalkable;
	cggl::Vector3 objectPosition;

protected:
	virtual void OnCollision(Entity& collisioner) {};
	virtual void DoDraw() = 0;
	virtual void DoUpdate() {}

	void SetWalkable(bool isWalkable) { GameObject::isWalkable = isWalkable; }

	static float MaxDimension;
public:
	GameObject(cggl::Vector3 position);
	GameObject(cggl::Vector3 position, bool isWalkable);
	~GameObject(void) {};

	void Draw();
	void Update(int deltaTimeMilis);

	bool IsWalkable() { return isWalkable; }
};

#endif