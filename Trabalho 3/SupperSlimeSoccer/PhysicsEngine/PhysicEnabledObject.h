#ifndef _PE_PEOBJECT_
#define _PE_PEOBJECT_

#include "cggl\MathUtils.h" //Trocar para tipo próprio
#include "BoundingBox.h"

namespace CGPhysicsEngine
{

class PhysicEnabledObject : public BoundingBox
{
private:	
	float _mass; 
	float _maximumVelocity;
	cggl::Vector3 _position;
	cggl::Vector3 _velocity;
	cggl::Vector3 _acceleration;
	cggl::Vector3 _force;

	void SetPosition(cggl::Vector3 position);
	void SetAcceleration(cggl::Vector3 acceleration) { _acceleration = acceleration; }
	void SetVelocity(cggl::Vector3 velocity) { _velocity = velocity; }
	void SetForce(cggl::Vector3 force) { _force = force; }
	cggl::Vector3 GetForce() { return _force; }
	
protected:
	void SetMass(float mass) { _mass = mass; }
	void SetMaximumVelocity(float maximumVelocity) { _maximumVelocity = maximumVelocity; }

	friend class ObjectCollision;
	friend class PhysicsEngine;
public:
	PhysicEnabledObject(cggl::Vector3 position, float mass, float maximumVelocity, cggl::Vector3 boundingBoxCenter, cggl::Vector3 boundingBoxDimensions);
	PhysicEnabledObject(cggl::Vector3 position, float mass, float maximumVelocity, cggl::Vector3 boundingBoxDimensions);
	~PhysicEnabledObject(void);
	
	void AddForce(cggl::Vector3 force) { _force += force; } 
	
	float GetMass() { return _mass; }
	float GetMaximumVelocity();
	cggl::Vector3 GetPosition() { return _position; }
	cggl::Vector3 GetVelocity() { return _velocity; }
	cggl::Vector3 GetAcceleration() { return _acceleration; }
};

}
#endif
