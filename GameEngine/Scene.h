#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
class Scene
{
private:
	std::string filename = "";
	std::list<Entity*> entities = std::list<Entity*>();
	std::string name = "";
	int id = 0;
	friend class SceneManager;

protected:
	Scene();
	~Scene();
	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON _json);

public:
	void AddEntity(Entity* _entity);
	void RemoveEntity(Entity* _entity);
	Entity* FindEntityById(int id);
};

#endif

