#include "Engine.h"

Engine* Engine::instance = nullptr;

void Engine::Initialize()
{
	DEBUG_LOG(0, "Engine::Initialize");
	Time::Instance().Initialize();
	assetManager = new AssetManager();
	sceneManager = new SceneManager();

	assetManager->Initialize();
	sceneManager->Initialize();
	RenderSystem::Instance().Initialize();

	json::JSON gameSettings = LoadJson("GameSettings.json");

	RenderSystem::Instance().Load(gameSettings);

	std::string scene_filename = Get(gameSettings, "DefaultScene").ToString();
	sceneManager->Load(scene_filename);
}

void Engine::Destroy()
{
	DEBUG_LOG(0, "Engine::Destroy");
	Time::Instance().Destroy();
	assetManager->Destroy();
	sceneManager->Destroy();
	RenderSystem::Instance().Destroy();

	delete assetManager;
	delete sceneManager;

	assetManager = nullptr;
	sceneManager = nullptr;

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
	sprite->Initialize();

	while (!quit)
	{
		GetInput();
		Time::Instance().Update();
		RenderSystem::Instance().Update();
	}

	sceneManager->Update();
}

void Engine::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT:
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				quit = true;
			}
			break;
		case SDL_MOUSEWHEEL:
			std::cout << "Mouse Event" << std::endl;
			break;
		}
	}
}