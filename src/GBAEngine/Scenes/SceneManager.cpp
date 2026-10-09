#include "SceneManager.h"

bool SceneManager::AddScene(const bn::string_view& name, Scene* scene) {
	if (scenes.full() || scenes.contains(name))
		return false;

	scenes.insert(name, scene);
	return true;
}

Scene* SceneManager::GetScene(const bn::string_view& name) {
	auto it = scenes.find(name);
	if (it != scenes.end())
		return it->second;

	return nullptr;
}

bool SceneManager::InitFirstScene(const bn::string_view& name) {
	Scene* scene = GetScene(name);
	if (scene == nullptr)
		return false;

	currentScene = scene;
	currentScene->OnEnter();
	return true;
}

bool SceneManager::SetNextScene(const bn::string_view& name) {
	Scene* scene = GetScene(name);
	if (scene == nullptr)
		return false;

	nextScene = scene;
	return true;
}

void SceneManager::UpdateCurrentScene() {
	if (nextScene != nullptr) {
		if (currentScene != nullptr)
			currentScene->OnExit();
		currentScene = nextScene;
		currentScene->OnEnter();
		nextScene = nullptr;
	}
	if (currentScene != nullptr)
		currentScene->Update();
}
