#include "Entity.h"

#include <gl\glut.h>

#include <cggl\App.h>

using namespace cggl;



Entity::Entity(EntityTypeFlag type, int walkingSpeed)
{
	entitySpeed = walkingSpeed;
	entityWalking = false;
	entityType = type;
}

Entity::~Entity(void)
{
}

void Entity::Draw()
{
	glPushMatrix();
		
		glTranslated(entityPosition.x, entityPosition.y, entityPosition.z);
		
		glRotatef(entityRotation, 0, 1, 0);

		DoDrawEntity();

	glPopMatrix();

	Object::Draw();
}

void Entity::Update(int deltaTimeMilis)
{
	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
	{

	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_DOWN))
	{

	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
	{

	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
	{

	}

	Object::Update(deltaTimeMilis);
}

bool Entity::BelongsToType(EntityTypeFlag type)
{
	return (GetType() && type) != 0;
}
