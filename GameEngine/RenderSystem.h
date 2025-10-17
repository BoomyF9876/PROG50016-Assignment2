#pragma once
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_

#include "StandardIncludes.h"

class IRenderable;

class RenderSystem
{
private:
	std::string name = "";
	int width = 0;
	int height = 0;
	bool fullscreen = false;

	std::list<IRenderable*> renderables = std::list<IRenderable*>();
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	friend class Engine;
	static RenderSystem* instance;

public:
	inline static RenderSystem& Instance()
	{
		if (instance == nullptr)
		{
			instance = new RenderSystem();
		}
		return *instance;
	}
	void AddRenderable(IRenderable* _renderable);
	void RemoveRenderable(IRenderable* _renderable);
	SDL_Renderer* GetRenderer() { return renderer; }

private:
	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON _json);

	inline explicit RenderSystem() = default;
	inline ~RenderSystem() = default;
	inline explicit RenderSystem(RenderSystem const&) = delete;
	inline RenderSystem& operator=(RenderSystem const&) = delete;
};

#endif