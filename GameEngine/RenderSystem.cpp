#include "RenderSystem.h"
#include "IRenderable.h"

RenderSystem* RenderSystem::instance = nullptr;

void RenderSystem::Initialize()
{
	DEBUG_LOG(4, "RenderSystem::Initialize");
	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void RenderSystem::Destroy()
{
	DEBUG_LOG(4, "RenderSystem::Destroy");
	renderables.clear();
	SDL_DestroyWindow(window);
	SDL_Quit();
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void RenderSystem::Update()
{
	DEBUG_LOG(4, "RenderSystem::Update");
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for (auto& renderable : renderables)
	{
		renderable->Render();
	}

	SDL_RenderPresent(renderer);
}

void RenderSystem::Load(json::JSON _json)
{
	DEBUG_LOG(4, "RenderSystem::Load");

	name = Get(_json, "name").ToString();
	width = Get(_json, "width").ToInt();
	height = Get(_json, "height").ToInt();
	fullscreen = Get(_json, "fullScreen").ToBool();

	DEBUG_LOG(8, "name :" + name);
	DEBUG_LOG(8, "width :" + std::to_string(width));
	DEBUG_LOG(8, "height :" + std::to_string(height));
	DEBUG_LOG(8, "fullScreen :" + std::to_string(fullscreen));
}

void RenderSystem::AddRenderable(IRenderable* _renderable)
{
	renderables.push_back(_renderable);
}

void RenderSystem::RemoveRenderable(IRenderable* _renderable)
{
	renderables.remove(_renderable);
}