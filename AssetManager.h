#pragma once
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

#include "Asset.h"
class AssetManager
{
private:
	std::list<Asset*> assets;

public:
	void Initialize();
	void Destroy();
};

#endif
