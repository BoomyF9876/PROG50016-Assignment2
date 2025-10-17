#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
class Scene
{
private:
	std::list<Entity*> entities = std::list<Entity*>();
	std::string name = "";
	int id = 0;

public:
	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON _json);

	void RemoveEntity(Entity* _entity);
	Entity* FindEntityById(int id);
};

#endif

