#ifndef _PACMAN_GAMEOBJ_
#define _PACMAN_GAMEOBJ_

#include <cggl\Object.h>
#include <cggl\MathUtils.h>

#include "Entity.h"
#include "BoardCoordinates.h"
#include "GameStaticSettings.h"

class GameObject : public cggl::Object
{
private: 
	bool isWalkable;
	cggl::Vector3 objectPosition;
	BoardCoordinates objectCoordinates;	

protected:
	virtual void DoDraw() = 0;
	virtual void DoUpdate(int deltaTimeMilis) {}

	void SetWalkable(bool isWalkable) { GameObject::isWalkable = isWalkable; }
	
public:
	GameObject(BoardCoordinates coords);
	GameObject(BoardCoordinates coords, bool isWalkable);
	~GameObject(void) {}

	void Draw();
	void Update(int deltaTimeMilis);

	virtual void OnCollision(Entity& collisioner) {};

	bool IsWalkable() { return isWalkable; }

	cggl::Vector3 GetPosition() { return objectPosition; }
	BoardCoordinates GetCoordinates() { return objectCoordinates; }
};

#endif