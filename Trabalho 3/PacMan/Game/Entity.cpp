#include "Entity.h"
#include "Board.h"

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

		Vector3& position = GetPosition();	

		glTranslated(position.x, position.y, position.z);
		
		glRotatef(GetRotation(), 0, 1, 0);

		if(IsEntityWalking())
			DoDrawWalkingAnimation(GetWalkingAnimationTime());
		else
			DoDrawEntity();

	glPopMatrix();

	Object::Draw();
}

void Entity::Update(int deltaTimeMilis)
{	
	if(IsEntityWalking())
	{
		AddWalkingAnimationTime(deltaTimeMilis);

		if(GetWalkingAnimationTime() >= GetSpeed())
		{
			entityWalkingTo = NULL;
			SetEntityWalking(false);			
		
			GameObject * obj = GetBoard().ObjectAt(BoardCoordinates::ConvertWorldToBoardCoordinates(GetPosition()));

			obj->OnCollision(*this);
		}
		else
		{
			Vector3 newPos = GetPosition() + (*entityWalkingTo * ((GetWalkingAnimationTime() / (float) GetSpeed())));
		
			SetPosition(newPos);
		}
	}

	DoUpdate(deltaTimeMilis);

	Object::Update(deltaTimeMilis);
}

bool Entity::BelongsToType(EntityTypeFlag type)
{
	return (GetType() && type) != 0;
}
	
void Entity::StartWalkingAnimation()
{
	SetEntityWalking(true);
	SetWalkingAnimationTime(0);
}

void Entity::SetRotationIfDifferent(float value)
{	
	if(GetRotation() != 3.14f) SetRotation(3.14f);
}

void Entity::Move(float angle, Vector3& to)
{
	SetRotationIfDifferent(angle);

	BoardCoordinates& coords = BoardCoordinates::ConvertWorldToBoardCoordinates(to);
	
	GameObject * obj = GetBoard().ObjectAt(coords);
	if(obj != NULL && obj->IsWalkable())
	{
		StartWalkingAnimation();
	}
}

void Entity::MoveUp()
{
	if(!IsEntityWalking())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(0, 0, -1);
		Move(3.14f, pos);
	}
}

void Entity::MoveDown()
{
	if(!IsEntityWalking())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(0, 0, 1);
		Move(0, pos);
	}
}

void Entity::MoveLeft()
{	
	if(!IsEntityWalking())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(-1, 0, 0);
		Move(-1.56f, pos);
	}
}

void Entity::MoveRight()
{
	if(!IsEntityWalking())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(1, 0, 0);
		Move(1.56f, pos);
	}
}

void Entity::SetBoard(Board& board) 
{ 
	entityBoard = &board; 
}

Board& Entity::GetBoard() 
{ 
	return *entityBoard; 
}