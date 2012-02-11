#include "Game.h"
#include "Board.h"
#include "PacMan.h"
#include "Ghost.h"

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
	board->AddEntity(*pac, BoardCoordinates(15, 16));
	
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
	static bool keyPressedLast = false;
	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_HOME))
	{
		static bool isFullScreen = false;

		if(isFullScreen && !keyPressedLast)
		{
			isFullScreen = false;
			glutReshapeWindow(800, 600);
			glutPositionWindow(50, 50);
		}
		else if(!keyPressedLast)
		{
			isFullScreen = true;
			glutFullScreen();
		}

		keyPressedLast = true;
	}
	else
		keyPressedLast = false;
	App::Update(deltaTimeMilis);
}
