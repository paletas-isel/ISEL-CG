#ifndef _PE_PEOBJECT_
#define _PE_PEOBJECT_

#include "cggl\MathUtils.h" //Trocar para tipo próprio

namespace CGPhysicsEngine
{

class PhysicEnabledObject
{
private:	
	float _mass;
	cggl::Vector3 _position;
	cggl::Vector3 _velocity;
	cggl::Vector3 _acceleration;

	void SetPosition(cggl::Vector3 position);
	void SetAcceleration(cggl::Vector3 acceleration);

protected:
	void SetMass(float mass);
	void AddForce(cggl::Vector3 force);
	void SetVelocity(cggl::Vector3 velocity);

	friend class ObjectCollision;
	friend class PhysicsEngine;
public:
	PhysicEnabledObject(cggl::Vector3 position, float mass);
	~PhysicEnabledObject(void);

	float GetMass();
	cggl::Vector3 GetPosition();
	cggl::Vector3 GetVelocity();
	cggl::Vector3 GetAcceleration();
};

}
#endif
