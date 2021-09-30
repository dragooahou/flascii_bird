#pragma once


#include <Windows.h>

class NYTimer {

public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;
	NYTimer();
	void start(void);
	float getElapsedSeconds(bool);
	unsigned long getElapsedMs(bool);

};
