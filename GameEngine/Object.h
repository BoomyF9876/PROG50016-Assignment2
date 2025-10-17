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
	void Initialize();
	void Destroy();
	void Load(json::JSON _json);

public:
	bool IsInitialized() { return initialized; };
	std::string& GetName() { return name; };
	int GetId() { return id; };

};

#endif