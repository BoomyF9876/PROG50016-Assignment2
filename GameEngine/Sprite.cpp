#include "Sprite.h"

void Sprite::Load(json::JSON _json)
{
	Component::Load(_json);
	DEBUG_LOG(14, "Sprite::Load");
	spriteName = Get(_json, "spriteName").ToString();
	DEBUG_LOG(16, "spriteName:" + spriteName);
}

void Sprite::Destroy()
{
	Component::Destroy();
	DEBUG_LOG(16, "Sprite::Destroy");
	DEBUG_LOG(18, "spriteName:" + spriteName);
	SDL_DestroyTexture(texture);
}

void Sprite::Initialize()
{
	Component::Initialize();
	DEBUG_LOG(16, "Sprite::Initialize");
	DEBUG_LOG(18, "spriteName:" + spriteName);

	SDL_Surface* surface = IMG_Load("Tacos.jpg");
	texture = SDL_CreateTextureFromSurface(RenderSystem::Instance().GetRenderer(),surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
}

void Sprite::Update()
{
	Component::Update();
	DEBUG_LOG(16, "Sprite::Update");
	DEBUG_LOG(18, "spriteName:" + spriteName);
}

void Sprite::Render()
{
	SDL_Rect dstrect = { 0, 0, size.x, size.y };
	SDL_RenderCopy(RenderSystem::Instance().GetRenderer(), texture, NULL, &dstrect);
}