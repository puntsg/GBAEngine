#pragma once
#include "Object.h"
#include "bn_vector.h"
#include "Spawner.h"

class Scene
{
protected:
	bn::vector<Object*, 16> ui;
	bn::vector<Object*, 64> objects;

public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void OnEnter() = 0;
	virtual void OnExit();
	virtual void Update();
};