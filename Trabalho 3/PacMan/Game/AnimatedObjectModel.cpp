#include "AnimatedObjectModel.h"


AnimatedObjectModel::AnimatedObjectModel(int animationDuration) : AnimatedModel(animationDuration)
{
}


AnimatedObjectModel::~AnimatedObjectModel(void)
{
}

void AnimatedObjectModel::Draw()
{
	DoDraw();
}