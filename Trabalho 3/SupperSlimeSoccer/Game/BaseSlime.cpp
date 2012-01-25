#include "BaseSlime.h"
#include <gl\glut.h>
#include "cggl\App.h"
#include <math.h>
#include "SuperSlimeSoccer.h"

using namespace cggl;

#define JUMP_DURATION 2 //In Seconds

BaseSlime::BaseSlime(BaseBall * ball, Vector3 position, int radius, short maxJumpHeight) : _body(radius), SpherePhysicObject(position, SLIME_MASS, radius)
{
	_maxJumpHeight = maxJumpHeight;
	_ball = ball;
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

//void BaseSlime::Update(int deltaTimeMilis)
//{
//	Object::Update(deltaTimeMilis);
//	
//	static int jumpTime;
//	static bool isJumping = false;
//
//	if(!isJumping && App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
//	{
//		jumpTime = 0;		
//		isJumping = true;
//	}
//	else if(isJumping)
//	{		
//		jumpTime += deltaTimeMilis;
//		
//		double jumpPos = ((double) jumpTime / 1000) / (PI * ((double) JUMP_DURATION / 10));
//
//		_position.y = sin(jumpPos) * _maxJumpHeight;
//
//		if(_position.y <= 0 || jumpTime > (JUMP_DURATION * 1000)) 
//		{
//			_position.y = 0; 
//			isJumping = false;
//		}
//	}
//
//	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
//	{
//		_position.x += _radius * ((double) deltaTimeMilis / 1000);
//	}
//	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
//	{
//		_position.x -= _radius * ((double) deltaTimeMilis / 1000);		
//	}
//
//	if(IsCollidingWithBall())
//	{
//		Vector3 x = _position - _ball->GetPosition();
//		x.Normalize();
//
//		Vector3 v1 = _velocityVector;
//		float x1 = x.DotProduct(v1);
//		Vector3 v1x = x * x1; 
//		Vector3 v1y = v1 - v1x;
//
//		x *= -1; 
//		Vector3 v2 = _ball->GetVelocity();
//		float x2 = x.DotProduct(v2);
//		Vector3 v2x = x * x2; 
//		Vector3 v2y = v2 - v2x;
//
//	}
//}

void BaseSlime::Update(int deltaTimeMilis)
{
	Object::Update(deltaTimeMilis);

	static bool isJumping = false;
	static int jumpTime = -1;

	if(!isJumping && App::Input->IsSpecialKeyPressed(GLUT_KEY_UP))
	{
		jumpTime = 0;		
		isJumping = true;
	}
	else if(isJumping)
	{		
		jumpTime += deltaTimeMilis;
		
		double jumpPos = ((double) jumpTime / 1000) / (PI * ((double) JUMP_DURATION / 10));
		
		double currHeight = sin(jumpPos) * _maxJumpHeight;
		
		Vector3 up = Vector3::UP;
		AddForce(up * currHeight * JUMP_DURATION);
		
		if(jumpTime > (JUMP_DURATION * 1000)) 
		{
			Vector3 speed = GetVelocity();
			speed.y = 0; 
			SetVelocity(speed);
			isJumping = false;
		}
	}

	if(App::Input->IsSpecialKeyPressed(GLUT_KEY_LEFT))
	{
		Vector3 left = Vector3::LEFT;
		AddForce(left * (2.5 * GetMass()));
	}
	else if(App::Input->IsSpecialKeyPressed(GLUT_KEY_RIGHT))
	{
		Vector3 right = Vector3::RIGHT;
		AddForce(right * (2.5 * GetMass()));
	}

	SuperSlimeSoccer::GetPhysicsEngine()->Process(this, deltaTimeMilis);
}

bool BaseSlime::IsCollidingWithBall()
{
	float distance = sqrt(pow(GetPosition().x - _ball->GetPosition().x, 2) + pow(GetPosition().y - _ball->GetPosition().y, 2) + pow(GetPosition().y - _ball->GetPosition().y, 2));
	float sumRadius = _radius + _ball->GetRadius();

	return distance < sumRadius;
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
