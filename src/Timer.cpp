#include "Timer.h"

Timer::Timer(void)
{
	started = false;
	paused = true;
	startTime = 0;
}

Timer::~Timer(void)
{
}

void Timer::start()
{
    //Start the timer
    started = true;
    paused = false;

    //Get the current clock time
    startTime = SDL_GetTicks();
}

void Timer::pause()
{
	//Pause the timer
    started = false;
    paused = true;
}

void Timer::reset()
{
	//Reset the timer
	startTime = SDL_GetTicks();

}

void Timer::stop()
{
	started = false;
	paused = false;

}

unsigned int Timer::millis()
{
	return SDL_GetTicks() - startTime;
}

bool Timer::isRunning()
{
	return started;
}