#include "Scene.h"

Entity* Scene::FindEntityById(int id)
{
	auto iterator = std::find_if(entities.begin(), entities.end(),
		[&](Entity* entity){ return entity->GetId() == id; }
	);
	return *iterator;
}

void Scene::RemoveEntity(Entity* _entity)
{
	_entity->Destroy();
	delete _entity;
	_entity = nullptr;
}

void Scene::Load(json::JSON _json)
{
	DEBUG_LOG(8, "Scene::Load");

	name = Get(_json, "name").ToString();
	id = Get(_json, "id").ToInt();

	DEBUG_LOG(10, "name :" + name);
	DEBUG_LOG(10, "id :" + std::to_string(id));
	
	json::JSON entityArr = Get(_json, "Entites");
	for (int i = 0; i < entityArr.size(); i++)
	{
		Entity* new_entity = new Entity();
		new_entity->Load(entityArr[i]);
		entities.push_back(new_entity);
	}
}

void Scene::Initialize()
{
	DEBUG_LOG(8, "Scene::Initialize");
	for (Entity* entity: entities)
	{
		entity->Initialize();
	}
}

void Scene::Update()
{
	DEBUG_LOG(8, "Scene::Update");
	for (Entity* entity : entities)
	{
		entity->Update();
	}
}

void Scene::Destroy()
{
	DEBUG_LOG(8, "Scene::Destroy");
	for (Entity* entity : entities)
	{
		RemoveEntity(entity);
	}

	entities.clear();
}