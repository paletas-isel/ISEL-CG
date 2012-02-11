#include "Ghost.h"
#include "GameStaticSettings.h"
#include "Board.h"

#include <gl\glut.h>

#include <math.h>

#include "ScatterAI.h"
#include "ChaseAI.h"

#include "DummyEntity.h"

using namespace cggl;

Ghost::Ghost(PacMan& pac, Board& board) : Entity(GhostEntity, 1000), entityPac(pac)
{
	SetBoard(board);

	GameObject * gate = GetBoard().ObjectOfType(GhostGate);
	DummyEntity * ent = new DummyEntity(gate->GetPosition());

	scatterAi = new ScatterAI(*ent, board);
	chaseAi = new ChaseAI(pac, board);
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
	static int timeElapsed = 0;
	if(timeElapsed < 10000)
	{
		scatterAi->ApplyAI(*this);
		timeElapsed += deltaTimeMilis;
	}
	else
	{
		chaseAi->ApplyAI(*this);
	}
}