#include "Board.h"

#include "Food.h"
#include "SpecialFood.h"
#include "Wall.h"
#include "Portal.h"
#include "Gate.h"
#include "GhostSpawner.h"
#include "GameStaticSettings.h"
#include "Ghost.h"
#include "ModelProvider.h"

#include <cggl\MathUtils.h>

#include <gl\glut.h>

using namespace std;
using namespace cggl;

Board::Board(vector<vector<BoardTuple *>> boardMap, ModelProvider& provider) : modelProvider(provider)
{
	map = boardMap;
	gameOver = false;
	ghostCount = 0;

	ConnectPortals();
}

Board::~Board(void)
{
}

void Board::ConnectPortals()
{
	static Portal * otherPortal;

	for(vector<vector<BoardTuple *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<BoardTuple *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(*it2 != NULL && (*it2)->type == PortalType)
			{
				Portal * portal = dynamic_cast<Portal*>((*it2)->obj);

				if(otherPortal == NULL)
				{
					otherPortal = portal;
					continue;
				}
				
				BoardCoordinates * validCoords = FindWalkableAround(portal->GetCoordinates());
				otherPortal->SetDestination(*validCoords);
				validCoords =  FindWalkableAround(otherPortal->GetCoordinates());
				portal->SetDestination(*validCoords);
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
	obj = ObjectAt(c1);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	BoardCoordinates c2 = BoardCoordinates( coord.boardX - 1, coord.boardY );
	obj = ObjectAt(c2);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	BoardCoordinates c3 = BoardCoordinates( coord.boardX, coord.boardY - 1 );
	obj = ObjectAt(c3);
	if(obj != NULL && obj->IsWalkable()) return &obj->GetCoordinates();

	return NULL;
}

Board * Board::LoadFrom(string file, ModelProvider& provider)
{
	return LoadFrom(ifstream(file), provider);
}

Board * Board::LoadFrom(ifstream file, ModelProvider& provider)
{
	static int collumnsSize = -1; 
	int lineNumber = 0;

	vector<vector<BoardTuple *>> map;
	
	if(!file) return NULL;

	while(!file.eof())
	{
		vector<BoardTuple *> line;

		char c; int currCollumns = 0;
		while(!file.eof() && (c = (char) file.get()) != '\n')
		{
			if(collumnsSize != -1 && currCollumns >= collumnsSize) break;
			
			BoardItemType type = (BoardItemType) (c - '0');
			if(type != Nothing)
			{
				BoardCoordinates coords = BoardCoordinates( currCollumns, lineNumber );
				GameObject * obj = CreateObject(type, provider, coords);
				BoardTuple * tuple = new BoardTuple(type, obj);
				line.push_back(tuple);
			}
			else
				line.push_back(NULL);

			currCollumns++;
		}

		if(collumnsSize == -1) collumnsSize = currCollumns;

		map.push_back(line);
		lineNumber++;
	}

	collumnsSize = -1;
	file.close();

	return new Board(map, provider);
}

GameObject * Board::CreateObject(BoardItemType type, ModelProvider& provider, BoardCoordinates& coords, ...)
{	
	switch(type)
	{
		case FoodType : 
			return new Food(provider.GetItemModel(FoodType), coords);
			
		case SpecialFoodType :
			return new SpecialFood(provider.GetItemModel(SpecialFoodType), coords);
			
		case PortalType :
			return new Portal(provider.GetItemModel(PortalType), coords);
			
		case GhostSpawnerType :
			return new GhostSpawner(provider.GetItemModel(GhostSpawnerType), coords);

		case GhostGate : 
			return new Gate(provider.GetAnimatedItemModel(GhostGate), coords);
			
		case Walls :
			return new Wall(provider.GetItemModel(Walls), coords);
			
		default :
			return NULL;
			
	}
}

void Board::Draw()
{
	glColor3f(0, 0, 0);

	for(vector<vector<BoardTuple *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<BoardTuple *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(*it2 != NULL)
				(*it2)->obj->Draw();
		}
	}

	for(list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it)
	{
		(*it)->Draw();
	}

	if(gameOver)
		glutBitmapLength(GLUT_BITMAP_9_BY_15, (const unsigned char *) "Game Over!");

	Object::Draw();
}

void Board::Update(int deltaTimeMilis)
{
	static int timeLeftGates = 2000;
	static bool gatesChangesPending = true, gateOpening = false, gateOpened = false;

	if(!gameOver)
	{
		if(pacman->GetLifes() == 0) 
		{
			gameOver = true;
			return;
		}

		if(GetGhostCount() == 0)
		{
			GameObject * spawner = ObjectOfType(GhostSpawnerType);
			for(int ix = 0; ix < GHOST_AMMOUNT; ++ix)
			{
				Ghost * ghost = new Ghost(modelProvider.GetEntityModel(GhostEntity), *pacman, *this);
				AddEntity(ghost, spawner->GetCoordinates());
			}
		}

		for(list<Entity *>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			Entity * entity = *it;
		
			entity->Update(deltaTimeMilis);

			if(entity->GetType() == PacmanEntity)
			{
				PacMan * pac = (PacMan *) entity;
				for(list<Entity *>::iterator it2 = entities.begin(); it2 != entities.end(); ++it2)
				{
					if(pac != (*it2) && pac->GetPosition() == (*it2)->GetPosition())
					{
						pac->OnCollision(*(*it2));
					}
				}
			}
		}

		for(vector<vector<BoardTuple *>>::iterator it = map.begin(); it != map.end(); ++it)
		{
			for(vector<BoardTuple *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
			{
				if(*it2 != NULL)
				{
					if(gatesChangesPending)
					{
						if((*it2)->type == GhostGate)
						{
							Gate * gate = dynamic_cast<Gate*>((*it2)->obj);	
						
							if(timeLeftGates <= 0)
							{		

								if(gate->IsOpen())
									gate->Close();
								else
								{
									gate->Open();
									gateOpening = true;
								}
							}
							else if(gate->IsOpen() && gateOpening)	
							{
								gateOpened = true;
								gateOpening = false;
							}
						}
					}

					(*it2)->obj->Update(deltaTimeMilis);
				}
			}
		}

		if(gateOpened) 
		{
			timeLeftGates = 5000;
			gateOpened = false;
		} 
		else if(timeLeftGates <= 0)
		{
			timeLeftGates = 2000;
			if(!gateOpening)
				gatesChangesPending = false;
		}
		else if(gatesChangesPending && !gateOpening)
			timeLeftGates -= deltaTimeMilis;
	}	

	Object::Update(deltaTimeMilis);
}


GameObject * Board::ObjectAt(BoardCoordinates& coords)
{
	int x, y = 0;
	for(vector<vector<BoardTuple *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		x = 0;
		for(vector<BoardTuple *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(coords.boardX == x && coords.boardY == y)
			{
				if(*it2 != NULL)
					return (*it2)->obj;
				return NULL;
			}			
			x++;	
		}		
		y++;
	}		

	return NULL;
}

GameObject * Board::ObjectOfType(BoardItemType type)
{
	for(vector<vector<BoardTuple *>>::iterator it = map.begin(); it != map.end(); ++it)
	{
		for(vector<BoardTuple *>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			if(*it2 != NULL && (*it2)->type == type)
			{
				return (*it2)->obj;
			}		
		}		
	}		

	return NULL;
}
	
void Board::AddEntity(Entity * entity, BoardCoordinates& place)
{
	entities.push_back(entity);
	entity->SetPosition(BoardCoordinates::ConvertBoardToWorldCoordinates(place));
	entity->SetBoard(*this);

	if(entity->BelongsToType(PacmanEntity))
		pacman = dynamic_cast<PacMan *>(entity);
	else if(entity->BelongsToType(GhostEntity))
		ghostCount++;
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