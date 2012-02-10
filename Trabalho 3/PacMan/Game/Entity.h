#ifndef _PACMAN_ENTITY_
#define _PACMAN_ENTITY_

#include <cggl\Object.h>
#include <cggl\MathUtils.h>

enum EntityTypeFlag
{
	GhostEntity = 0x1,
	PacmanEntity = 0x2
};

class Board;

class Entity : public cggl::Object
{
private:
	EntityTypeFlag entityType;

	int entitySpeed;
	bool entityWalking;
	int walkingAnimationTime;
	float entityRotation;
	cggl::Vector3 entityPosition;
	cggl::Vector3 * entityWalkingTo;

	void StartWalkingAnimation();
	void Entity::SetRotationIfDifferent(float value);

	Board * entityBoard;

	void Move(float angle, cggl::Vector3& to);

protected:
	virtual void DoDrawEntity() = 0;
	virtual void DoDrawWalkingAnimation(int deltaTimeMilis) = 0;
	virtual void DoUpdate(int deltaTimeMilis) = 0;

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

public:
	Entity(EntityTypeFlag type, int walkingSpeed);
	~Entity(void);

	void Draw();
	void Update(int deltaTimeMilis);

	bool IsEntityWalking() { return entityWalking; }
	void SetEntityWalking(bool isWalking) { entityWalking = isWalking; }

	int GetSpeed() { return entitySpeed; }

	float GetRotation() { return entityRotation; }
	void SetRotation(float rotation) { entityRotation = rotation; }

	int GetWalkingAnimationTime() { return walkingAnimationTime; }
	void SetWalkingAnimationTime(int time) { walkingAnimationTime = time; }
	void AddWalkingAnimationTime(int time) { walkingAnimationTime += time; }

	cggl::Vector3& GetPosition() { return entityPosition; }
	void SetPosition(cggl::Vector3 position) { entityPosition = position; }

	EntityTypeFlag GetType() { return entityType; }

	bool BelongsToType(EntityTypeFlag type);

	void SetBoard(Board& board);
	Board& GetBoard();
};

#endif