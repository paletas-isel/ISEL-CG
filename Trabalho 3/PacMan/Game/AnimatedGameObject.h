#ifndef _PACMAN_ANIMATEDGAMEOBJ_
#define _PACMAN_ANIMATEDGAMEOBJ_

#include "gameobject.h"
#include "AnimatedObjectModel.h"

class AnimatedGameObject :
	public GameObject
{
private:
	bool animationStarted;
	AnimatedModel * animatedModel;

protected:
	virtual void DoUpdate(int deltaTimeMilis) {}

	bool HasAnimationStarted() { return animationStarted; }
	void SetAnimationStatus(bool status) { animationStarted = status; } 

	AnimatedModel * GetAnimatedModel() { return animatedModel; }

public:
	AnimatedGameObject(AnimatedObjectModel * model, BoardCoordinates coords);
	AnimatedGameObject(AnimatedObjectModel * model, BoardCoordinates coords, bool isWalkable);
	~AnimatedGameObject(void);

	virtual void Draw();
	void Update(int deltaTimeMilis);

	virtual void OnCollision(Entity& collisioner) {};
};

#endif