#ifndef _PACMAN_BOARDCOORDS_
#define _PACMAN_BOARDCOORDS_

#include <cggl\MathUtils.h>

struct BoardCoordinates
{
	int boardX;
	int boardY;

	BoardCoordinates(int x, int y) : boardX(x), boardY(y) { }
	
	static cggl::Vector3 ConvertBoardToWorldCoordinates(BoardCoordinates& coords);
	static BoardCoordinates ConvertWorldToBoardCoordinates(cggl::Vector3& coords);
};

#endif