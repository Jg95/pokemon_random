#pragma once

#include <iostream>
#include <SDL.h>

using namespace std;

class Timer
{
public:

	Timer(void);
	~Timer(void);

	void start();
	void pause();
	void reset();
	void stop();
	unsigned int millis();
	bool isRunning();

private:

	bool started;
	bool paused;
	unsigned int startTime;
	unsigned int currentTime;
};



