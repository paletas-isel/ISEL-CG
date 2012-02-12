#include "ScoreBoardComponent.h"

#include <gl/glut.h>

#include <stdio.h>

ScoreBoardComponent::ScoreBoardComponent(PacMan * pac)
{
	pacman = pac;
}


ScoreBoardComponent::~ScoreBoardComponent(void)
{
}

void ShowString(char * string)
{
	for(int ix = 0; string[ix] != 0; ++ix)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[ix]);
}

void ScoreBoardComponent::Draw()
{
	if(pacman != 0)
	{
		char buffer[64];

		glRasterPos2f(30, 30);

		sprintf(buffer, "Score : %d", pacman->GetFoodEaten());
		ShowString(buffer);
		
		glRasterPos2f(30, 10);

		sprintf(buffer, "Lifes : %d", pacman->GetLifes());
		ShowString(buffer);
	}

	Object::Draw();
}