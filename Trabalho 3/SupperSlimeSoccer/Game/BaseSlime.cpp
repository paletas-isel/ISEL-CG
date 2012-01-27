#include "BaseSlime.h"
#include <gl\glut.h>
#include "cggl\App.h"
#include <math.h>
#include "SuperSlimeSoccer.h"

using namespace cggl;

#define SLIME_MASS 20

#define JUMP_DURATION 2 //In Seconds
#define MOVING_FORCE ( 500 )
#define JUMP_FORCE ( 1500 )

BaseSlime::BaseSlime(Vector3 position, int radius) : _body(radius), _obj(position, SLIME_MASS, radius, radius)
{
	_radius = radius;
}


BaseSlime::~BaseSlime(void)
{
}

void BaseSlime::SetColor(float red, float green, float blue, float alpha)
{
	_red = red;
	_green = green;
	_blue = blue;
	_alpha = alpha;
}

void BaseSlime::Update(int deltaTimeMilis)
{
	Object::Update(deltaTimeMilis);
	
	if(GetPosition().y == 0 && App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
	{
		Vector3 up = Vector3::UP;
		SuperSlimeSoccer::GetPhysicsEngine().AddForce(_obj, up * JUMP_FORCE);
	}
	
	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		Vector3 left = Vector3::LEFT;
		SuperSlimeSoccer::GetPhysicsEngine().AddForce(_obj, left * MOVING_FORCE);
	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		Vector3 right = Vector3::RIGHT;
		SuperSlimeSoccer::GetPhysicsEngine().AddForce(_obj, right * MOVING_FORCE);
	}

	SuperSlimeSoccer::GetPhysicsEngine().Process(_obj, deltaTimeMilis);
}

void BaseSlime::SetMaterial()
{
	glColor4f(_red, _green, _blue, _alpha);

}

void BaseSlime::Draw()
{
	Object::Draw();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glPushMatrix();		
	
		glTranslatef(GetPosition().x, GetPosition().y, GetPosition().z);
		
		SetMaterial();

		_body.Draw(30);
	
	glPopMatrix();

	glDisable(GL_LIGHTING);
}
