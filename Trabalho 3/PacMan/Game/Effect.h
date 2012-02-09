#ifndef _PACMAN_EFFECT_
#define _PACMAN_EFFECT_

#include "Entity.h"

class Effect
{
private:
	EntityTypeFlag targetTypes;

public:
	Effect(EntityTypeFlag targetTypes) { Effect::targetTypes = targetTypes; }
	~Effect(void) {};

	EntityTypeFlag GetTargetTypes() { return targetTypes; }
	virtual void ApplyEffect(Entity& entity) = 0;
};

#endif

