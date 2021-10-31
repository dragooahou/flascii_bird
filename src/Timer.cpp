#include <Windows.h>
#include "Timer.h"

Timer::Timer() {
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

void Timer::Start() {
	QueryPerformanceCounter(&lastUpdateTime);
}

float Timer::GetElapsedSeconds(bool restart = false) {
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}

unsigned long Timer::GetElapsedMs(bool restart = false) {
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	unsigned long elapsed = (unsigned long)((float)elapsedLong / (float)freq);
	return elapsed;
}

Timer &Timer::GetInstance() {
    static Timer nyTimer;
    return nyTimer;
}
