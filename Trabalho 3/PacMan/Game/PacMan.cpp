#include "PacMan.h"
#include "GameStaticSettings.h"
#include "Ghost.h"

#include <cggl\App.h>

#include <gl\glut.h>

using namespace cggl;

PacMan::PacMan(void) : Entity(PacmanEntity, 200)
{

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
	
void PacMan::OnCollision(Ghost ghost)
{
	RemoveLife();
}