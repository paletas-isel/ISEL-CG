#include "AnimatedModel.h"


AnimatedModel::AnimatedModel(int animationDuration)
{
	AnimatedModel::animationDuration = animationDuration;
	animationTime = 0;
}


AnimatedModel::~AnimatedModel(void)
{
}

void AnimatedModel::DrawAnimation()
{
	float p = GetAnimationTime() / (float) GetAnimationDuration();

	if(p <= 1)
		DoDrawAnimation(p);
	else
	{
		animationCompleted = true;
		animationTime = 0;
		Draw();
	}
}