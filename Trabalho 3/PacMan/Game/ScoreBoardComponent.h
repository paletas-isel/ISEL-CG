#ifndef _PACMAN_SCOREBOARD_
#define _PACMAN_SCOREBOARD_

#include <cggl\Object.h>

#include "PacMan.h"

class ScoreBoardComponent : public cggl::Object
{
private:
	PacMan * pacman;

public:
	ScoreBoardComponent(PacMan * pac);
	~ScoreBoardComponent(void);

	void Draw();
};

#endif