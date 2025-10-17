#pragma once
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include "StandardIncludes.h"
#include "SDL.h"
#include "SDL_image.h"

class IRenderable;

class RenderSystem
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	static RenderSystem* instance;
	std::string name;
	int width;
	int height;
	bool fullscreen;
	std::list<IRenderable*> renderables;
	friend class Engine;

public:
	inline static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}

	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON _json);

	void AddRenderable(IRenderable* _renderable);
	void RemoveRenderable(IRenderable* _renderable);
	SDL_Renderer* GetRenderer() { return renderer; }

	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;
};

#endif