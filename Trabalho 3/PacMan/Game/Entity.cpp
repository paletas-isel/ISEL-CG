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
	walkingAnimationSpeed = 200;
}

Entity::~Entity(void)
{
}

void Entity::Draw()
{
	glPushMatrix();

		Vector3& position = GetPosition() + inBetweenPosition;	

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
	static Vector3 lastPosition;
	static int waitTimeLeft = -1;
	static bool canWalk = true;
	
	DoUpdate(deltaTimeMilis);

	if(!canWalk)
	{
		waitTimeLeft -= deltaTimeMilis;
		if(waitTimeLeft <= 0)
			canWalk = true;
		else			
			SetEntityWalking(false);
	}

	if(IsEntityWalking() && canWalk)
	{
		AddWalkingAnimationTime(deltaTimeMilis);

		if(GetWalkingAnimationTime() >= GetWalkingAnimationSpeed())
		{
			SetPosition(GetPosition() + *entityWalkingTo);
			
			entityWalkingTo = NULL;
			SetEntityWalking(false);	
			inBetweenPosition = Vector3::ZERO;

			GameObject * obj = GetBoard().ObjectAt(BoardCoordinates::ConvertWorldToBoardCoordinates(GetPosition()));
			
			lastPosition = GetPosition();

			if(obj != NULL)
				obj->OnCollision(*this);

			waitTimeLeft = GetSpeed();
			canWalk = false;
		}
		else
		{		
			inBetweenPosition = (*entityWalkingTo * (GetWalkingAnimationTime() / (float) GetWalkingAnimationSpeed()));
		}
	}
	else if(lastPosition != GetPosition())
	{
		lastPosition = GetPosition();
		
		GameObject * obj = GetBoard().ObjectAt(BoardCoordinates::ConvertWorldToBoardCoordinates(GetPosition()));

		if(obj != NULL)
			obj->OnCollision(*this);
	}

	Object::Update(deltaTimeMilis);
}

bool Entity::BelongsToType(EntityTypeFlag type)
{
	return (GetType() & type) != 0;
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
	SetEntityWalking(true);
	StartWalkingAnimation();
}

void Entity::MoveUp()
{
	if(!IsEntityWalking() && CanMoveUp())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(0, 0, -1 * OBJECT_DIMENSION);
		Move(3.14f, pos + *entityWalkingTo);
	}
}

void Entity::MoveDown()
{
	if(!IsEntityWalking() && CanMoveDown())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(0, 0, 1 * OBJECT_DIMENSION);
		Move(0, pos + *entityWalkingTo);
	}
}

void Entity::MoveLeft()
{	
	if(!IsEntityWalking() && CanMoveLeft())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(-1 * OBJECT_DIMENSION, 0, 0);
		Move(-1.56f, pos + *entityWalkingTo);
	}
}

void Entity::MoveRight()
{
	if(!IsEntityWalking() && CanMoveRight())
	{
		Vector3& pos = GetPosition();
		entityWalkingTo = new Vector3(1 * OBJECT_DIMENSION, 0, 0);
		Move(1.56f, pos + *entityWalkingTo);
	}
}

bool Entity::CanMoveUp()
{
	Vector3 pos = GetPosition();
	BoardCoordinates& coords = BoardCoordinates::ConvertWorldToBoardCoordinates(pos + Vector3(0, 0, -1 * OBJECT_DIMENSION));
	
	return CanMove(coords);
}

bool Entity::CanMoveDown()
{
	Vector3 pos = GetPosition();
	BoardCoordinates& coords = BoardCoordinates::ConvertWorldToBoardCoordinates(pos + Vector3(0, 0, 1 * OBJECT_DIMENSION));
	
	return CanMove(coords);
}

bool Entity::CanMoveLeft()
{
	Vector3 pos = GetPosition();
	BoardCoordinates& coords = BoardCoordinates::ConvertWorldToBoardCoordinates(pos + Vector3(-1 * OBJECT_DIMENSION, 0, 0));
	
	return CanMove(coords);
}

bool Entity::CanMoveRight()
{
	Vector3 pos = GetPosition();
	BoardCoordinates& coords = BoardCoordinates::ConvertWorldToBoardCoordinates(pos + Vector3(1 * OBJECT_DIMENSION, 0, 0));

	return CanMove(coords);
}

bool Entity::CanMove(BoardCoordinates& to)
{
	GameObject * obj = GetBoard().ObjectAt(to);
	return (obj == NULL || obj->IsWalkable());
}

void Entity::SetBoard(Board& board) 
{ 
	entityBoard = &board; 
}

Board& Entity::GetBoard() 
{ 
	return *entityBoard; 
}