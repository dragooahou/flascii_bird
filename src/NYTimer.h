#pragma once

class NYTimer {

public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;
	NYTimer();
	void start(void);
	float getElapsedSeconds(bool);
	unsigned long getElapsedMs(bool);

};
