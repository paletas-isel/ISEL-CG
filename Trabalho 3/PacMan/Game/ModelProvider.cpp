#include "ModelProvider.h"

#include "FoodModel.h"
#include "SpecialFoodModel.h"
#include "GateModel.h"
#include "WallModel.h"
#include "PortalModel.h"

using namespace std;

ModelProvider::ModelProvider(void)
{
	entityModels.insert(pair<BoardItemType, ObjectModel>(FoodType, new FoodModel()));
	entityModels.insert(pair<BoardItemType, ObjectModel>(SpecialFoodType, new SpecialFoodModel()));
	entityModels.insert(pair<BoardItemType, ObjectModel>(PortalType, new PortalModel()));
	entityModels.insert(pair<BoardItemType, ObjectModel>(Walls, new WallModel()));
	entityModels.insert(pair<BoardItemType, ObjectModel>(GhostGate, new GateModel()));
}


ModelProvider::~ModelProvider(void)
{
}

ObjectModel * ModelProvider::GetItemModel(BoardItemType type)
{
	map<BoardItemType, ObjectModel *>::iterator it;
	if((it = objectModels.find(type)) != objectModels.end())
	{
		return (*it).second;
	}
	return NULL;
}

AnimatedObjectModel * ModelProvider::GetAnimatedItemModel(BoardItemType type)
{
	ObjectModel * model = GetItemModel(type);
	if(model != NULL)
		return dynamic_cast<AnimatedObjectModel *>(model);
	return NULL;
}

EntityModel * ModelProvider::GetEntityModel(EntityTypeFlag type)
{
	map<EntityTypeFlag, EntityModel *>::iterator it;
	if((it = entityModels.find(type)) != entityModels.end())
	{
		return (*it).second;
	}
}