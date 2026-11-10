#include "Scene.h"
#include "Object.h"
void Scene::OnExit() {
	// Clear the spawner
	SPAWN.ClearSpawnedObjects();
	//Destroy ALl the objects
	for (Object* o : objects)
		delete o;
	objects.clear();
	//Clear UI
	for (Object* o : ui)
		delete o;
	ui.clear();
}
void Scene::Update() {
	///Destrruction
	for (int i = objects.size() - 1; i >= 0; i--) // com iterem a un vector que decreix, anem de dreta a esquerra
	{
		if (objects[i]->IsPendingDestroy())
		{
			delete objects[i];
			objects.erase(objects.begin() + i);
		}
	}
	//Spawning
	while (SPAWN.GetSpawnedObjectsCount() > 0) {
		objects.push_back(SPAWN.GetSpawnedObject());
	}
	//Updating
	for (Object* o : objects)
		o->Update();
	for (Object* o : ui)
		o->Update();
}