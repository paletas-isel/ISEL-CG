#include "SuperSlimeSoccer.h"
#include "BaseSlime.h"
#include "cggl\FPSCounter.h"
#include "BaseBall.h"

using namespace cggl;
using namespace CGPhysicsEngine;

PhysicsEngine SuperSlimeSoccer::_physicEngine = PhysicsEngine(0);

SuperSlimeSoccer::SuperSlimeSoccer(void)
{
}

SuperSlimeSoccer::~SuperSlimeSoccer(void)
{
}

PhysicsEngine& SuperSlimeSoccer::GetPhysicsEngine()
{
	return _physicEngine;
}

void SuperSlimeSoccer::CreateScene()
{
	RegisterObject(new FPSCounter());
	
	BaseBall * ball = new BaseBall(Vector3(0, 3, 0), 1);
	BaseSlime * slime1 = new BaseSlime(Vector3(0, 0, 0), 2);
	BaseSlime * slime2 = new BaseSlime(Vector3(0, 0, 0), 2);
	
	RegisterObject(slime1);

	GetPhysicsEngine().RegisterObject(slime1->GetPhysicObject());

	App::Camera->LookAt(Vector3(0, 0, 20), Vector3(0, 1, -200), Vector3::UP); 	
}

void SuperSlimeSoccer::Update(int deltaTimeMilis)
{
	App::Update(deltaTimeMilis);
}

void SuperSlimeSoccer::Draw()
{
	App::Draw();
}
