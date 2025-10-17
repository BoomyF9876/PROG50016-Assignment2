#include "Engine.h"

int main()
{
	Engine::Instance().Initialize();
	Engine::Instance().GameLoop();
	Engine::Instance().Destroy();

	return 0;
}