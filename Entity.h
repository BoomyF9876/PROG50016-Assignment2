#pragma once

#include "Sprite.h"
class Entity: public Object
{
private:
	std::list<Component*> components;
public:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON _json);

	void RemoveComponent(Component* _component);
	Component* CreateComponent(std::string _componentType);
};

