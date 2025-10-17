#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL.h"
#include "Component.h"
#include "IRenderable.h"

class SDL_Texture;

class Sprite: public Component, public IRenderable
{
private:
	std::string spriteName;
	SDL_Texture* texture;
	SDL_Point size;

protected:
	void Render() override;

public:
	Sprite() = default;
	~Sprite() = default;

	void Initialize() override;
	void Destroy() override;
	void Update() override;
	void Load(json::JSON _json) override;
};

#endif
