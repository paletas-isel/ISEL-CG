#include "DummyEntity.h"
#include "NoModel.h"

using namespace cggl;

DummyEntity::DummyEntity(Vector3& position) : Entity((EntityTypeFlag) -1, new NoModel(), -1)
{
	SetPosition(position);
}


DummyEntity::~DummyEntity(void)
{
}
