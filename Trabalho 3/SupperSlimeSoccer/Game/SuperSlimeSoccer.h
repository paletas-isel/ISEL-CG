#include "cggl\App.h"
#include "physicsengine\PhysicsEngine.h"

#pragma once

class SuperSlimeSoccer : public cggl::App
{
private:
	static CGPhysicsEngine::PhysicsEngine _physicEngine;
public:
	SuperSlimeSoccer(void);
	~SuperSlimeSoccer(void);

	void CreateScene();
    void Update(int deltaTimeMilis);
	void Draw();

	static CGPhysicsEngine::PhysicsEngine * GetPhysicsEngine();
};

