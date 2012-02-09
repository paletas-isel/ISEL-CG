#include "GameObject.h"

#include <gl\glut.h>

using namespace cggl;

Vector3 MaxDimensions(10, 10, 10);

GameObject::GameObject(cggl::Vector3 position)
{ 
	objectPosition = position;
	GameObject::isWalkable = true; 
}

GameObject::GameObject(cggl::Vector3 position, bool isWalkable)
{ 
	objectPosition = position;
	GameObject::isWalkable = isWalkable; 
}

void GameObject::Draw()
{
	glPushMatrix();

		DoDraw();

	glPopMatrix();

	Object::Draw();
}
	
void GameObject::Update(int deltaTimeMilis)
{
	DoUpdate();

	Object::Update(deltaTimeMilis);
}