#ifndef _PACMAN_BOARD_
#define _PACMAN_BOARD_

#include <string>
#include <fstream>
#include <vector>
#include <list>

#include <cggl\Object.h>

#include "Entity.h"
#include "GameObject.h"
#include "BoardCoordinates.h"
#include "PacMan.h"

enum BoardItemType
{
	Nothing = 0,
	FoodType = 1,
	SpecialFoodType = 2,
	GhostSpawnerType = 6,
	PortalType = 7,
	GhostGate = 8,
	Walls = 9
};

struct BoardTuple
{
	BoardItemType type;
	GameObject * obj;

	BoardTuple(BoardItemType type, GameObject* obj) : type(type), obj(obj) { }
};

class Board : public cggl::Object
{
private:
	std::vector<std::vector<BoardTuple *>> map;
	std::list<Entity *> entities;
	PacMan * pacman;
	cggl::Vector3 * pacmanStartPosition; 

	Board(std::vector<std::vector<BoardTuple *>> boardMap);

	void ConnectPortals();
	BoardCoordinates * FindWalkableAround(BoardCoordinates coord);

	bool gameOver;
	int ghostCount;

public:
	~Board(void);

	void Draw();
	void Update(int deltaTimeMilis);

	std::list<Entity *>& GetEntities(EntityTypeFlag types);
	GameObject * ObjectAt(BoardCoordinates& coords);
	
	GameObject * ObjectOfType(BoardItemType type);

	static Board * LoadFrom(std::string file);
	static Board * LoadFrom(std::ifstream file);

	void AddEntity(Entity& entity, BoardCoordinates& place);

	static GameObject * CreateObject(BoardItemType type, BoardCoordinates& coords, ...);

	int GetGhostCount() { return ghostCount; }
};

#endif