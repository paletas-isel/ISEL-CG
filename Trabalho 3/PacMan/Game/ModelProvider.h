#ifndef _PACMAN_MODELPROVIDER_
#define _PACMAN_MODELPROVIDER_

#include "Board.h"
#include "Entity.h"
#include "EntityModel.h"
#include "ObjectModel.h"
#include "AnimatedObjectModel.h"

#include <map>

class ModelProvider
{
private:
	static std::map<BoardItemType, ObjectModel *> objectModels;
	static std::map<EntityTypeFlag, EntityModel *> entityModels;

	ModelProvider(void);
	~ModelProvider(void);

public:

	static ObjectModel * GetItemModel(BoardItemType type);
	static AnimatedObjectModel * GetAnimatedItemModel(BoardItemType type);
	static EntityModel * GetEntityModel(EntityTypeFlag type);
};

#endif