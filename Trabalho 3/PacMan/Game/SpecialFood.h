#ifndef _PACMAN_SPECIALFOOD_
#define _PACMAN_SPECIALFOOD_

#include "Food.h"

#include <cggl\MathUtils.h>

class SpecialFood : public Food
{
public:
	SpecialFood(cggl::Vector3 position);
	~SpecialFood(void);
};

#endif