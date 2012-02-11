#include "DummyEntity.h"

using namespace cggl;

DummyEntity::DummyEntity(Vector3& position) : Entity((EntityTypeFlag) -1, -1)
{
	SetPosition(position);
}


DummyEntity::~DummyEntity(void)
{
}
