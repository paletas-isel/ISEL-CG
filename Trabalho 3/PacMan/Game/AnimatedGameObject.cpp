#include "AnimatedGameObject.h"

#include <gl\glut.h>

AnimatedGameObject::AnimatedGameObject(AnimatedObjectModel& model, BoardCoordinates coords) : GameObject(model, coords), animatedModel(model)
{

}

AnimatedGameObject::AnimatedGameObject(AnimatedObjectModel& model, BoardCoordinates coords, bool isWalkable) : GameObject(model, coords, isWalkable), animatedModel(model)
{

}

AnimatedGameObject::~AnimatedGameObject(void)
{
}
 
void AnimatedGameObject::Draw()
{
	glPushMatrix();

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHTING);
		glEnable(GL_AMBIENT_AND_DIFFUSE);
		glColorMaterial ( GL_FRONT_AND_BACK, GL_EMISSION ) ;
		glEnable ( GL_COLOR_MATERIAL ) ;
		
		glTranslatef(GetPosition().x, GetPosition().y, GetPosition().z);	

		if(HasAnimationStarted())
			GetAnimatedModel().DrawAnimation();
		else
			GetModel().Draw();

		glDisable(GL_LIGHTING);

	glPopMatrix();

	Object::Draw();
}

void AnimatedGameObject::Update(int deltaTimeMilis)
{
	if(HasAnimationStarted())
		GetAnimatedModel().AddAnimationTime(deltaTimeMilis);

	DoUpdate(deltaTimeMilis);

	Object::Update(deltaTimeMilis);
}