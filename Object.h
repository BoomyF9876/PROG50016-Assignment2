#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "StandardIncludes.h"
class Object
{
private:
	bool initialized = false;
	std::string name = "";
	int id = 0;

protected:
	Object() = default;
	~Object() = default;

public:
	void Initialize();
	void Destroy();
	
	bool IsInitialized() { return initialized; };
	std::string& GetName() { return name; };
	int GetId() { return id; };
	void Load(json::JSON _json);
};

#endif