#include "SceneManager.h"

void SceneManager::Initialize()
{
	DEBUG_LOG(4, "SceneManager::Initialize");
}

void SceneManager::Load(std::string& _filename)
{
	DEBUG_LOG(4, "SceneManager::Load");
	json::JSON testScene = LoadJson(_filename);

	json::JSON sceneManager = Get(testScene, "SceneManager");
	json::JSON sceneArr = Get(sceneManager, "scenes");
	for (int i = 0; i < sceneArr.size(); i++)
	{
		Scene* new_scene = new Scene();
		new_scene->Load(sceneArr[i]);
		new_scene->Initialize();

		scenes.push_back(new_scene);
	}
}

void SceneManager::Update()
{
	DEBUG_LOG(4, "SceneManager::Update");
	for (Scene* scene : scenes)
	{
		scene->Update();
	}
}

void SceneManager::Destroy()
{
	DEBUG_LOG(4, "SceneManager::Destroy");
	for (Scene* scene : scenes)
	{
		scene->Destroy();
		delete scene;
		scene = nullptr;
	}

	scenes.clear();
}