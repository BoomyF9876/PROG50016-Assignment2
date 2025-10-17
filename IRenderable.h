#pragma once
#include "RenderSystem.h"

class IRenderable
{
private:
	friend class RenderSystem;
protected:
	IRenderable();
	~IRenderable();
	virtual void Render() = 0;
};

