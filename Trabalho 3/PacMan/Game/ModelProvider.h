#ifndef _PACMAN_MODELPROVIDER_
#define _PACMAN_MODELPROVIDER_

#include "EntityModel.h"
#include "ObjectModel.h"
#include "AnimatedObjectModel.h"
#include "Board.h"
#include "Entity.h"

class ModelProvider
{
private:

public:
	ModelProvider(void);
	~ModelProvider(void);

	ObjectModel * GetItemModel(BoardItemType type);
	AnimatedObjectModel * GetAnimatedItemModel(BoardItemType type);
	EntityModel * GetEntityModel(EntityTypeFlag type);
};

#endif