#ifndef _PACMAN_BOARD_
#define _PACMAN_BOARD_

#include <string>
#include <fstream>
#include <vector>
#include <list>

#include <cggl\Object.h>

#include "Entity.h"
#include "GameObject.h"

enum BoardItemType
{
	Nothing = 0,
	FoodType = 1,
	SpecialFoodType = 2,
	PortalType = 7,
	MonsterGate = 8,
	Walls = 9
};

class Board : public cggl::Object
{
private:
	std::vector<std::vector<GameObject *>> map;

	Board(std::vector<std::vector<GameObject *>> boardMap);

public:
	~Board(void);

	void Draw();
	void Update(int deltaTimeMilis);

	std::list<Entity *> GetEntities(EntityTypeFlag types);

	static Board LoadFrom(std::string file);
	static Board LoadFrom(std::ifstream file);

	static GameObject * CreateObject(BoardItemType type, int boardX, int boardY);
};

#endif