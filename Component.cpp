#include "Component.h"

void Component::Load(json::JSON _json)
{
	Object::Load(_json);
	DEBUG_LOG(14, "Component::Load");
}

void Component::Destroy()
{
	Object::Destroy();
	DEBUG_LOG(14, "Component::Destroy");
}

void Component::Initialize()
{
	Object::Initialize();
	DEBUG_LOG(14, "Component::Initialize");
}

void Component::Update()
{
	DEBUG_LOG(14, "Component::Update");
	DEBUG_LOG(16, "Component Id: " + std::to_string(GetId()));
	DEBUG_LOG(16, "Component Name: " + GetName());
}