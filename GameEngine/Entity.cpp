#include "Entity.h"

Component* Entity::CreateComponent(std::string _componentType)
{
	if (_componentType == "Sprite")
	{
		return new Sprite();
	}
	else
	{
		M_ASSERT(0, "Unknown component type");
	}
}

void Entity::RemoveComponent(Component* _component)
{
	_component->Destroy();
}

void Entity::Load(json::JSON _json)
{
	Object::Load(_json);
	DEBUG_LOG(14, "Entity::Load");

	json::JSON new_components = Get(_json, "Components");
	for (int i = 0; i < new_components.size(); i++)
	{
		Component* new_component = CreateComponent(Get(new_components[i], "componentType").ToString());
		new_component->Load(new_components[i]);
		components.push_back(new_component);
	}
}

void Entity::Initialize()
{
	Object::Initialize();
	DEBUG_LOG(12, "Entity::Initialize");
	for (Component* component : components)
	{
		component->Initialize();
	}
}

void Entity::Update()
{
	DEBUG_LOG(12, "Entity::Update");
	DEBUG_LOG(14, "Entity Id: " + std::to_string(GetId()));
	DEBUG_LOG(14, "Entity Name: " + GetName());

	for (Component* component : components)
	{
		component->Update();
	}
}

void Entity::Destroy()
{
	Object::Destroy();
	DEBUG_LOG(14, "Entity::Destroy");
	for (Component* component : components)
	{
		RemoveComponent(component);
	}

	components.clear();
}