#include "Engine.h"
#include "StandardIncludes.h"
#include "EngineTime.h"
#include "RenderSystem.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "InputManager.h"

Engine* Engine::instance = nullptr;

void Engine::Initialize()
{
	DEBUG_LOG(0, "Engine::Initialize");

	Time::Instance().Initialize();
	RenderSystem::Instance().Initialize();
	SceneManager::Instance().Initialize();
	AssetManager::Instance().Initialize();
	InputManager::Instance().Initialize();

	json::JSON gameSettings = LoadJson("GameSettings.json");
	const std::string scene_filename = Get(gameSettings, "DefaultScene").ToString();

	RenderSystem::Instance().Load(Get(gameSettings, "RenderSystem"));
	SceneManager::Instance().LoadScene(scene_filename);
}

void Engine::Destroy()
{
	DEBUG_LOG(0, "Engine::Destroy");
	Time::Instance().Destroy();
	RenderSystem::Instance().Destroy();

	//delete assetManager;
	//delete sceneManager;

	//assetManager = nullptr;
	//sceneManager = nullptr;

	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void Engine::GameLoop()
{
	DEBUG_LOG(0, "Engine::GameLoop");
	Sprite* sprite = new Sprite();
	/*sprite->Initialize();

	while (!quit)
	{
		GetInput();
		Time::Instance().Update();
		RenderSystem::Instance().Update();
	}

	sceneManager->Update();*/
}

//void Engine::GetInput()
//{
//	SDL_Event event;
//	while (SDL_PollEvent(&event))
//	{
//		switch (event.type)
//		{
//		case SDL_WINDOWEVENT:
//			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
//			{
//				quit = true;
//			}
//			break;
//		case SDL_MOUSEWHEEL:
//			std::cout << "Mouse Event" << std::endl;
//			break;
//		}
//	}
//}