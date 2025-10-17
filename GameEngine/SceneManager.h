#pragma once
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "Scene.h"
class SceneManager
{
private:
	std::list<Scene*> scenes = std::list<Scene*>();
	friend class Engine;
	static SceneManager* instance;

public:
	inline static SceneManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new SceneManager();
		}
		return *instance;
	}

	void LoadScene(const std::string& _filename);
	void UnLoadScene(const std::string& _filename);

private:
	void Initialize();
	void Update();
	void Destroy();

	inline explicit SceneManager() = default;
	inline ~SceneManager() = default;
	inline explicit SceneManager(SceneManager const&) = delete;
	inline SceneManager& operator=(SceneManager const&) = delete;
};

#endif
