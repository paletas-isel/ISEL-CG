#include "Board.h"

#include "Food.h"
#include "SpecialFood.h"
#include "Wall.h"
#include "Portal.h"
#include "Gate.h"

#include <cggl\MathUtils.h>

using namespace std;
using namespace cggl;

Board::Board(vector<vector<GameObject *>> boardMap)
{
	map = boardMap;
}


Board::~Board(void)
{
}

Board Board::LoadFrom(string file)
{
	return LoadFrom(ifstream(file));
}

Board Board::LoadFrom(ifstream file)
{
	static int collumnsSize = -1; 
	int lineNumber = 0;

	vector<vector<GameObject *>> map;

	while(!file.eof())
	{
		vector<GameObject *> line;

		char c; int currCollumns = 0;
		while((c = (char) file.get()) != '\n')
		{
			currCollumns++;

			if(collumnsSize != -1 && currCollumns > collumnsSize) break;

			line.push_back(CreateObject((BoardItemType) c, lineNumber, currCollumns));
		}

		if(collumnsSize == -1) collumnsSize = currCollumns;

		map.push_back(line);
		lineNumber++;
	}

	collumnsSize = -1;
	file.close();
	return Board(map);
}

Vector3 ConvertBoardToWorldCoordinates(int boardX, int boardY)
{
	return Vector3((float) boardX, 0, (float) boardY);
}

GameObject * Board::CreateObject(BoardItemType type, int boardX, int boardY)
{
		
	Vector3 coordinates = ConvertBoardToWorldCoordinates(boardX, boardY);
	
	switch(type)
	{
		case FoodType : 
			return new Food(coordinates);
			
		case SpecialFoodType :
			return new SpecialFood(coordinates);
			
		case PortalType :
			return new Portal(coordinates);
			
		case MonsterGate : 
			return new Gate(coordinates);
			
		case Walls :
			return new Wall(coordinates);
			
		default :
			return NULL;
			
	}
}

void Board::Draw()
{

}

void Board::Update(int deltaTimeMilis)
{

}