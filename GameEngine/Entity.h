#pragma once

#include "Sprite.h"
class Entity: public Object
{
private:
	std::list<Component*> components = std::list<Component*>();
	SDL_Point position = {0, 0};

protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON _json);

public:
	SDL_Point GetPosition();
	Component* CreateComponent(std::string& _componentType);
	void RemoveComponent(Component* _component);
};

