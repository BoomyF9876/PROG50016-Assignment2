#include "Object.h"

void Object::Load(json::JSON _json)
{
	DEBUG_LOG(12, "---- Object::Load ----");
	id = Get(_json, "id").ToInt();
	name = Get(_json, "name").ToString();
	DEBUG_LOG(14, "Object Id: " + std::to_string(id));
	DEBUG_LOG(14, "Object Name: " + name);
}

void Object::Initialize()
{
	DEBUG_LOG(12, "---- Object::Initialize ----");
	DEBUG_LOG(14, "Object Id: " + std::to_string(id));
	DEBUG_LOG(14, "Object Name: " + name);
}

void Object::Destroy()
{
	DEBUG_LOG(12, "---- Object::Destroy ----");
	DEBUG_LOG(14, "Object Id: " + std::to_string(id));
	DEBUG_LOG(14, "Object Name: " + name);
}