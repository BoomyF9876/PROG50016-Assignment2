#pragma once
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

class InputManager
{
private:
	friend class Engine;
	static InputManager* instance;

public:
	inline static InputManager& Instance()
	{
		if (instance == nullptr)
		{
			instance = new InputManager();
		}
		return *instance;
	};

private:
	void Initialize();
	void Update();
	void Destroy();

	inline explicit InputManager() = default;
	inline ~InputManager() = default;
	inline explicit InputManager(InputManager const&) = delete;
	inline InputManager& operator=(InputManager const&) = delete;
};

#endif

