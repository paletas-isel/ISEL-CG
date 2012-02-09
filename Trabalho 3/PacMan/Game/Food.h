#ifndef _PACMAN_FOOD_
#define _PACMAN_FOOD_

#include "GameObject.h"
#include "Effect.h"
#include "Entity.h"

class Food : public GameObject
{
private:
	bool hasBeenEaten;

protected:
	virtual Effect& GetEffect();

	void OnCollision(Entity& collisioner);

	virtual void DoDraw();

public:
	Food(cggl::Vector3 position);
	~Food(void);

	void SetEaten() { hasBeenEaten = true; }
	bool HasBeenEaten() { return hasBeenEaten; }
};

#endif