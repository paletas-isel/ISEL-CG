#ifndef _PACMAN_GAMEOBJ_
#define _PACMAN_GAMEOBJ_

#include <cggl\Object.h>
#include <cggl\MathUtils.h>

#include "Entity.h"
#include "BoardCoordinates.h"
#include "GameStaticSettings.h"

#include "ObjectModel.h"

class GameObject : public cggl::Object
{
private: 
	bool isWalkable;
	cggl::Vector3 objectPosition;
	BoardCoordinates objectCoordinates;	

	ObjectModel& objectModel;

protected:
	virtual void DoUpdate(int deltaTimeMilis) {}

	void SetWalkable(bool isWalkable) { GameObject::isWalkable = isWalkable; }
	
	ObjectModel& GetModel() { return objectModel; }

public:
	GameObject(ObjectModel& model, BoardCoordinates coords);
	GameObject(ObjectModel& model, BoardCoordinates coords, bool isWalkable);
	~GameObject(void) {}

	virtual void Draw();
	void Update(int deltaTimeMilis);

	virtual void OnCollision(Entity& collisioner) {};

	bool IsWalkable() { return isWalkable; }

	cggl::Vector3 GetPosition() { return objectPosition; }
	BoardCoordinates GetCoordinates() { return objectCoordinates; }
};

#endif