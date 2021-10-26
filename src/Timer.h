#pragma once


#include <Windows.h>

class Timer {

    Timer();

public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

    Timer(Timer &other) = delete;
    void operator=(const Timer &) = delete;

	void Start();
	float GetElapsedSeconds(bool restart);
	unsigned long GetElapsedMs(bool restart);

    static Timer& GetInstance();
};
