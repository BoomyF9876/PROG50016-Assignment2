#pragma once
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "Scene.h"
class SceneManager
{
private:
	std::list<Scene*> scenes;

public:
	void Initialize();
	void Destroy();
	void Update();
	void Load(std::string& _filename);
};

#endif
