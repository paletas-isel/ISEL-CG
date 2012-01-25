#include "BoxPhysicObject.h"

using namespace cggl;

namespace CGPhysicsEngine
{
	
BoxPhysicObject::BoxPhysicObject(cggl::Vector3 position, cggl::Vector3 dimension, float mass, cggl::Vector3 normals[]) : PhysicEnabledObject(position, mass)
{
	_normals = normals;
	_dimension = dimension;
}


BoxPhysicObject::~BoxPhysicObject(void)
{
}

cggl::Vector3 * BoxPhysicObject::GetNormals()
{
	return _normals;
}

cggl::Vector3 BoxPhysicObject::GetDimension()
{
	return _dimension;
}

}