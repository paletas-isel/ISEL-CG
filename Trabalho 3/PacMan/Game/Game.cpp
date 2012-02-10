#include "Game.h"
#include "Board.h"
#include "PacMan.h"

#include <cggl\FPSCounter.h>

using namespace cggl;

Game::Game(void)
{
}


Game::~Game(void)
{
}

void Game::CreateScene()
{
	Board * board = Board::LoadFrom("BoardDesigns/classic.board");
	PacMan * pac = new PacMan();
	board->AddEntity(*pac, BoardCoordinates(15, 23));

	RegisterObject(board);

#ifdef _DEBUG
	RegisterObject(new FPSCounter());
#endif

	App::Camera->LookAt(Vector3(150, 400, 300), Vector3(150, -500, 0), Vector3::UP); 	
}

void Game::Draw()
{
	App::Draw();
}

void Game::Update(int deltaTimeMilis)
{
	App::Update(deltaTimeMilis);
}
