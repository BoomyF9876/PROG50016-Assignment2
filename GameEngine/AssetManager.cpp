#include "AssetManager.h"

void AssetManager::Initialize()
{
	DEBUG_LOG(4, "AssetManager::Initialize");
}

void AssetManager::Destroy()
{
	DEBUG_LOG(4, "AssetManager::Destroy");

	assets.clear();
}