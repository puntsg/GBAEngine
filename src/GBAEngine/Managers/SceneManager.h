#pragma once
#include "bn_unordered_map.h"
#include "bn_string_view.h"
#include "../Entities/Scene.h"

#define SM SceneManager::Instance()
class SceneManager
{
private:
	static constexpr int MAX_SCENES = 16;

	bn::unordered_map<bn::string_view, Scene*, MAX_SCENES> scenes;
	Scene* currentScene = nullptr;
	Scene* nextScene = nullptr;
	SceneManager() = default;
	SceneManager(SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

public:
	inline static SceneManager& Instance() {
		static SceneManager sm;
		return sm;
	}
	bool AddScene(const bn::string_view& name, Scene* scene);
	Scene* GetScene(const bn::string_view& name);
	bool InitFirstScene(const bn::string_view& name);
	inline Scene* GetCurrentScene() const { return currentScene; }
	bool SetNextScene(const bn::string_view& name);
	void UpdateCurrentScene();
};
