#include "AnimatedModel.h"


AnimatedModel::AnimatedModel(int animationDuration)
{
	AnimatedModel::animationDuration = animationDuration;
}


AnimatedModel::~AnimatedModel(void)
{
}

void AnimatedModel::DrawAnimation()
{
	DoDrawAnimation(GetAnimationTime() / (float) GetAnimationDuration());
}