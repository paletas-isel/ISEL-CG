#include "Ghost.h"
#include "GameStaticSettings.h"
#include "Board.h"

#include <gl\glut.h>

#include <math.h>

using namespace cggl;

Ghost::Ghost(PacMan& pac) : Entity(GhostEntity, 1000), entityPac(pac)
{
}


Ghost::~Ghost(void)
{
}

void Ghost::DoDrawEntity()
{
	glutSolidCone(OBJECT_DIMENSION / 2.0f, OBJECT_DIMENSION, 10, 10); 
}

void Ghost::DoDrawWalkingAnimation(int deltaTimeMilis)
{
	glutSolidCone(OBJECT_DIMENSION / 2.0f, OBJECT_DIMENSION, 10, 10); 
}

void Ghost::DoUpdate(int deltaTimeMilis)
{
	
}