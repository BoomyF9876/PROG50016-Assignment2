#pragma once
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

#include "Asset.h"
class AssetManager
{
private:
	std::list<Asset*> assets = std::list<Asset*>();
	friend class Engine;

	static AssetManager* instance;
public:
	inline static AssetManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new AssetManager();
		}
		return *instance;
	}

private:
	void Initialize();
	void Update();
	void Destroy();
	void Load(json::JSON _json);

	inline explicit AssetManager() = default;
	inline ~AssetManager() = default;
	inline explicit AssetManager(AssetManager const&) = delete;
	inline AssetManager& operator=(AssetManager const&) = delete;
};

#endif
