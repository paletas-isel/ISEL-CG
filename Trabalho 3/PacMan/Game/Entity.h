#ifndef _PACMAN_ENTITY_
#define _PACMAN_ENTITY_

#include <cggl\Object.h>
#include <cggl\MathUtils.h>

enum EntityTypeFlag
{
	GhostEntity = 0x1,
	PacmanEntity = 0x2
};

class Entity : public cggl::Object
{
private:
	EntityTypeFlag entityType;

	int entitySpeed;
	bool entityWalking;
	float entityRotation;
	cggl::Vector3 entityPosition;

protected:
	virtual void DoDrawEntity() = 0;
	virtual void StartWalkingAnimation(int durationInMilis) = 0;

public:
	Entity(EntityTypeFlag type, int walkingSpeed);
	~Entity(void);

	void Draw();
	void Update(int deltaTimeMilis);

	cggl::Vector3 GetPosition() { return entityPosition; }
	void SetPosition(cggl::Vector3 position) { entityPosition = position; }

	EntityTypeFlag GetType() { return entityType; }

	bool BelongsToType(EntityTypeFlag type);
};

#endif