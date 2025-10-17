#include "IRenderable.h"

IRenderable::IRenderable() { 
	RenderSystem::Instance().AddRenderable(this);
};

IRenderable::~IRenderable() {
	RenderSystem::Instance().RemoveRenderable(this);
};

void IRenderable::Render()
{

};