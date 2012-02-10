#include "Board.h"

#include "Food.h"
#include "SpecialFood.h"
#include "Wall.h"
#include "Portal.h"
#include "Gate.h"

#include <cggl\MathUtils.h>

#include <gl\glut.h>

using namespace std;
using namespace cggl;

Board::Board(vector<vector<GameObject *>> boardMap)
{
	map = boardMap;

	ConnectPortals();
}

Board::~Board(void)
{
}

void Board::ConnectPortals()
{
	static Portal * otherPortal;

	for(vector<vector<GameObject *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<GameObject *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			Portal * portal = dynamic_cast<Portal*>(*it2);

			if(portal != NULL)
			{
				if(otherPortal == NULL)
				{
					otherPortal = portal;
					continue;
				}
				
				BoardCoordinates * validCoords = FindWalkableAround(portal->GetCoordinates());
				otherPortal->SetDestination(validCoords);
				validCoords =  FindWalkableAround(otherPortal->GetCoordinates());
				portal->SetDestination(validCoords);
			}
		}
	}
}


BoardCoordinates * Board::FindWalkableAround(BoardCoordinates coord)
{
	GameObject * obj;

	BoardCoordinates c = BoardCoordinates( coord.boardX + 1, coord.boardY );
	obj = ObjectAt(c);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	BoardCoordinates c1 = BoardCoordinates( coord.boardX, coord.boardY + 1 );
	obj = ObjectAt(c);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	BoardCoordinates c2 = BoardCoordinates( coord.boardX - 1, coord.boardY );
	obj = ObjectAt(c);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	BoardCoordinates c3 = BoardCoordinates( coord.boardX, coord.boardY - 1 );
	obj = ObjectAt(c);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	return NULL;
}

Board * Board::LoadFrom(string file)
{
	return LoadFrom(ifstream(file));
}

Board * Board::LoadFrom(ifstream file)
{
	static int collumnsSize = -1; 
	int lineNumber = 0;

	vector<vector<GameObject *>> map;
	
	if(!file) return NULL;

	while(!file.eof())
	{
		vector<GameObject *> line;

		char c; int currCollumns = 0;
		while((c = (char) file.get()) != '\n')
		{
			if(collumnsSize != -1 && currCollumns > collumnsSize) break;

			BoardCoordinates coords = BoardCoordinates( currCollumns, lineNumber );
			line.push_back(CreateObject((BoardItemType) (c - '0'), coords));

			currCollumns++;
		}

		if(collumnsSize == -1) collumnsSize = currCollumns;

		map.push_back(line);
		lineNumber++;
	}

	collumnsSize = -1;
	file.close();

	return new Board(map);
}

GameObject * Board::CreateObject(BoardItemType type, BoardCoordinates& coords, ...)
{	
	switch(type)
	{
		case FoodType : 
			return new Food(coords);
			
		case SpecialFoodType :
			return new SpecialFood(coords);
			
		case PortalType :
			return new Portal(coords);
			
		case MonsterGate : 
			return new Gate(coords);
			
		case Walls :
			return new Wall(coords);
			
		default :
			return NULL;
			
	}
}

void Board::Draw()
{
	glColor3f(0, 0, 0);

	for(vector<vector<GameObject *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<GameObject *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(*it2 != NULL)
				(*it2)->Draw();
		}
	}

	for(list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		(*it)->Draw();
	}

	Object::Draw();
}

void Board::Update(int deltaTimeMilis)
{
	for(list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		Entity * entity = *it;
		
		entity->Update(deltaTimeMilis);
	}

	for(vector<vector<GameObject *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<GameObject *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(*it2 != NULL)
				(*it2)->Update(deltaTimeMilis);
		}
	}

	Object::Update(deltaTimeMilis);
}


GameObject * Board::ObjectAt(BoardCoordinates& coords)
{
	int x, y = 0, maxX = 0;
	bool hasMax = false;
	for(vector<vector<GameObject *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		x = 0;
		for(vector<GameObject *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(coords.boardX == x && coords.boardY == y)
			{
				return *it2;
			}			
			x++;	
		}		
		y++;
	}		

	return NULL;
}
	
void Board::AddEntity(Entity& entity, BoardCoordinates& place)
{
	entities.push_back(&entity);
	entity.SetPosition(BoardCoordinates::ConvertBoardToWorldCoordinates(place));
	entity.SetBoard(*this);
}

list<Entity *>& Board::GetEntities(EntityTypeFlag types)
{
	list<Entity *> * validEntities = new list<Entity *>();
	for(list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if(((*it)->GetType() & types) != 0)
			validEntities->push_back(*it);
	}
	return *validEntities;
}