#include "ObjectCollision.h"
#include <math.h>
#include "cggl\MathUtils.h"

using namespace cggl;

namespace CGPhysicsEngine
{

	bool ObjectCollision::AreObjectsColliding(PhysicEnabledObject * obj1, PhysicEnabledObject * obj2)
	{
		return false;
	}

	bool ObjectCollision::AreObjectsColliding(SpherePhysicObject * obj1, SpherePhysicObject * obj2)
	{
		float distance = sqrt(pow(obj1->GetPosition().x - obj2->GetPosition().x, 2) + pow(obj1->GetPosition().y - obj2->GetPosition().y, 2) + pow(obj1->GetPosition().y - obj2->GetPosition().y, 2));
		float sumRadius = obj1->GetRadius() + obj2->GetRadius();

		return distance < sumRadius;
	}
		
	bool ObjectCollision::AreObjectsColliding(SpherePhysicObject * obj1, BoxPhysicObject * obj2)
	{
		return AreObjectsColliding(obj2, obj1);
	}

	bool ObjectCollision::AreObjectsColliding(BoxPhysicObject * obj1, SpherePhysicObject * obj2)
	{
		float distance = sqrt(pow(obj1->GetPosition().x - obj2->GetPosition().x, 2) + pow(obj1->GetPosition().y - obj2->GetPosition().y, 2) + pow(obj1->GetPosition().y - obj2->GetPosition().y, 2));
		
		return false;
	}

	bool ObjectCollision::AreObjectsColliding(BoxPhysicObject * obj1, BoxPhysicObject * obj2)
	{
		return false;
	}

	/*
	 * As seen in http://wp.freya.no/3d-math-and-physics/simple-sphere-sphere-collision-detection-and-collision-response/  	
	 */
	void ObjectCollision::ProcessCollisionResponse(PhysicEnabledObject * obj1, PhysicEnabledObject * obj2)
	{
		Vector3 x = obj1->GetPosition() - obj2->GetPosition();
		x.Normalize();

		Vector3 v1 = obj1->GetVelocity();
		float x1 = x.DotProduct(v1);
		Vector3 v1x = x * x1; 
		Vector3 v1y = v1 - v1x;

		x *= -1; 
		Vector3 v2 = obj2->GetVelocity();
		float x2 = x.DotProduct(v2);
		Vector3 v2x = x * x2; 
		Vector3 v2y = v2 - v2x;

		float obj1Mass = obj1->GetMass(), obj2Mass = obj2->GetMass();

		Vector3 obj1Speed = v1x * ((obj1Mass - obj2Mass) / (obj1Mass + obj2Mass)) + v2x * ((2 * obj2Mass) / (obj1Mass + obj2Mass)) + v1y;
		Vector3 obj2Speed = v1x * ((2 * obj1Mass) / (obj1Mass + obj2Mass)) + v2x * ((obj1Mass - obj2Mass) / (obj1Mass + obj2Mass)) + v2y;

		obj1->SetVelocity(obj1Speed);
		obj2->SetVelocity(obj2Speed);
	}
}