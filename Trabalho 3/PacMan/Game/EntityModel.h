#ifndef _PACMAN_ENTITYMODEL_
#define _PACMAN_ENTITYMODEL_

#include "model.h"
#include "AnimatedModel.h"

class EntityModel :
	public Model
{
private:
	int animationTime, animationDuration;

protected:
	int GetAnimationTime() { return animationTime; }
	void AddAnimationTime(int time) { animationTime += time; }

	int GetAnimationDuration() { return animationDuration; }
	void SetAnimationDuration(int duration) { animationDuration = duration; }

	virtual void DoDrawAnimation(float percentageCompleted) = 0;

public:
	EntityModel(int duration);
	~EntityModel(void);

	virtual void Draw() = 0;
};

#endif