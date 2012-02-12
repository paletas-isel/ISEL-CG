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

void Ghost::DoUpdate(int deltaTimeMilis)
{
	static Gate * gate = (Gate *) GetBoard().ObjectOfType(GhostGate);
	if(gate != NULL && gate->IsOpen())
	{
		scatterAi->ApplyAI(*this);
	}
	else
	{
		chaseAi->ApplyAI(*this);
	}
}