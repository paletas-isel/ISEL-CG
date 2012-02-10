#include "GameObject.h"

#include <gl\glut.h>

using namespace cggl;

GameObject::GameObject(BoardCoordinates coords) : objectCoordinates(coords)
{ 
	objectPosition = BoardCoordinates::ConvertBoardToWorldCoordinates(objectCoordinates) * OBJECT_DIMENSION + Vector3(OBJECT_DIMENSION / 2, 0, OBJECT_DIMENSION / 2);
	
	GameObject::isWalkable = true; 
}

GameObject::GameObject(BoardCoordinates coords, bool isWalkable) : objectCoordinates(coords)
{ 
	objectPosition = BoardCoordinates::ConvertBoardToWorldCoordinates(objectCoordinates) * OBJECT_DIMENSION + Vector3(OBJECT_DIMENSION / 2, 0, OBJECT_DIMENSION / 2);
	GameObject::isWalkable = isWalkable; 
}

void GameObject::Draw()
{
	glPushMatrix();

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
		glEnable(GL_AMBIENT_AND_DIFFUSE);
		glColorMaterial ( GL_FRONT_AND_BACK, GL_EMISSION ) ;
		glEnable ( GL_COLOR_MATERIAL ) ;
		
		glTranslatef(objectPosition.x, objectPosition.y, objectPosition.z);	

		DoDraw();

		glDisable(GL_LIGHTING);

	glPopMatrix();

	Object::Draw();
}
	
void GameObject::Update(int deltaTimeMilis)
{
	DoUpdate();

	Object::Update(deltaTimeMilis);
}