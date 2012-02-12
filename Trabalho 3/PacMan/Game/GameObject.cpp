#include "GameObject.h"

#include <gl\glut.h>

using namespace cggl;

GameObject::GameObject(ObjectModel * model, BoardCoordinates coords) : objectModel(model), objectCoordinates(coords)
{ 
	objectPosition = BoardCoordinates::ConvertBoardToWorldCoordinates(objectCoordinates);
	
	GameObject::isWalkable = true; 
}

GameObject::GameObject(ObjectModel * model, BoardCoordinates coords, bool isWalkable) : objectModel(model), objectCoordinates(coords)
{ 
	objectPosition = BoardCoordinates::ConvertBoardToWorldCoordinates(objectCoordinates);
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

		if(GetModel() != 0)
			GetModel()->Draw();

		glDisable(GL_LIGHTING);

	glPopMatrix();

	Object::Draw();
}
	
void GameObject::Update(int deltaTimeMilis)
{
	DoUpdate(deltaTimeMilis);

	Object::Update(deltaTimeMilis);
}