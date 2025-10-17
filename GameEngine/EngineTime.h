#pragma once
#ifndef _TIME_H_
#define _TIME_H_

#include <chrono>

class Time
{
private:
	static Time* instance;
	int frameCount = 0;
	std::chrono::duration<float> deltaTime{};
	std::chrono::time_point<std::chrono::system_clock> beginTime{};
	std::chrono::time_point<std::chrono::system_clock> endTime{};
	std::chrono::duration<float> totalTime{};
	friend class Engine;

public:
	inline static Time& Instance()
	{
		if (instance == nullptr)
		{
			instance = new Time();
		}
		return *instance;
	}

	float DeltaTime() { return deltaTime.count(); };
	float TotalTime() { return totalTime.count(); };
	int FrameCount() { return frameCount; };

private:
	void Initialize();
	void Update();
	void Destroy();

	inline explicit Time() = default;
	inline ~Time() = default;
	inline explicit Time(Time const&) = delete;
	inline Time& operator=(Time const&) = delete;
};

#endif