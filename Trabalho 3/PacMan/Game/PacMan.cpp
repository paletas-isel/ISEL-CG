#include "PacMan.h"
#include "GameStaticSettings.h"
#include "Ghost.h"

#include <cggl\App.h>

#include <gl\glut.h>

using namespace cggl;

PacMan::PacMan(EntityModel * model) : Entity(PacmanEntity, model, 200)
{
	lifes = 2;
	eatenFoodCount = 0;
	hasInitial = false;
}

PacMan::~PacMan(void)
{
}

void PacMan::DoDrawEntity()
{
	glColor3f(1, 1, 0);
	glutSolidSphere(OBJECT_DIMENSION / 2, PACMAN_DETAIL, PACMAN_DETAIL);
}

void PacMan::DoDrawWalkingAnimation(int deltaTimeMilis)
{
	DoDrawEntity();
}

void PacMan::DoUpdate(int deltaTimeMilis)
{
	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
	{
		MoveUp();
	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_DOWN))
	{
		MoveDown();
	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		MoveLeft();
	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		MoveRight();
	}
}
	
void PacMan::OnCollision(Entity& ghost)
{
	RemoveLife();

	SetPosition(initialPosition);
}

void PacMan::SetPosition(cggl::Vector3 position)
{
	if(!hasInitial)
	{
		initialPosition = position;
		hasInitial = true;
	}
	Entity::SetPosition(position);
}