#ifndef _PACMAN_ANIMATEDMODEL_
#define _PACMAN_ANIMATEDMODEL_

#include "Model.h"

class AnimatedModel : public Model
{
private:
	int animationDuration;
	int animationTime;

protected:
	virtual void DoDrawAnimation(float percentageCompleted) = 0;

public:
	AnimatedModel(int animationDuration);
	~AnimatedModel(void);

	void DrawAnimation();

	int GetAnimationTime() { return animationTime; }
	void AddAnimationTime(int time) { animationTime += time; }

	int GetAnimationDuration() { return animationDuration; }
	void SetAnimationDuration(int duration) { animationDuration = duration; }
};

#endif