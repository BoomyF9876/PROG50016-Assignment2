#pragma once
#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include "Object.h"
class Component : public Object
{
protected:
	Entity* owner;
	virtual void Initialize();
	virtual void Update();
	virtual void Destroy();
	virtual void Load(json::JSON _json);
private:
	friend class Entity;
};

#endif