#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"
class Component: public Object
{
protected:
	Component() = default;
	~Component() = default;

public:
	virtual void Initialize();
	virtual void Destroy();
	virtual void Update();
	virtual void Load(json::JSON _json);
};

#endif