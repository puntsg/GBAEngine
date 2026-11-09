#pragma once

#include "bn_deque.h"
#include "Object.h"

#define SPAWN Spawner::Instance()

class Spawner
{
private:
	bn::deque<Object*, 32> spawnedObjects;

	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator =(const Spawner&) = delete;

public:
	inline static Spawner& Instance() {
		static Spawner spawner;
		return spawner;
	}


	inline void SpawnObject(Object* obj) {
		spawnedObjects.push_back(obj);
	}

	inline Object* GetSpawnedObject() {
		if (spawnedObjects.empty())
			return NULL;

		Object* o = spawnedObjects.front();
		spawnedObjects.pop_front();
		return o;
	}

	inline int GetSpawnedObjectsCount() {
		return spawnedObjects.size();
	}
	inline void ClearSpawnedObjects() {
		while (!spawnedObjects.empty()) {
			delete spawnedObjects.front();
			spawnedObjects.pop_front();
		}
	}
};