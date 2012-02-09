#ifndef _PACMAN_GAME_
#define _PACMAN_GAME_

#include <cggl/App.h>

class Game : public cggl::App
{
public:
	Game(void);
	~Game(void);

	void CreateScene();
	void Draw();
	void Update(int deltaTimeMilis);
};

#endif