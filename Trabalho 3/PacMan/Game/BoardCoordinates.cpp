#include "BoardCoordinates.h"
#include "GameStaticSettings.h"

#include <math.h>

using namespace cggl;

Vector3 BoardCoordinates::ConvertBoardToWorldCoordinates(BoardCoordinates& coords)
{
	return Vector3((float) coords.boardX * OBJECT_DIMENSION + OBJECT_DIMENSION / 2, 0, (float) coords.boardY * OBJECT_DIMENSION + OBJECT_DIMENSION / 2);
}

BoardCoordinates BoardCoordinates::ConvertWorldToBoardCoordinates(cggl::Vector3& coords)
{
	return BoardCoordinates((int) floor(coords.x / OBJECT_DIMENSION), (int) floor(coords.z / OBJECT_DIMENSION));
}