#pragma once

#include <iostream>
#include <SDL.h>
#include "Vector2D.h"
#include "Constants.h"
#include "Timer.h"
#include "Sprite.h"

using namespace std;

class Animation: public Sprite
{
public:

	Animation(void);
	~Animation(void);

	void setPosition(Vector2D inpos);
	void setSpaceInterval(Vector2D inStartPosition, Vector2D inEndPosition);
	void setSequence(int dim, int *inSequence, int *inTimeInterval);
	
	bool isEnded();

	void start();
	void start(Vector2D inpos);

	void animate();
	void animate(Vector2D inpos);

	void hold();
	void hold(Vector2D inpos);

	void stand();
	void stand(int inPeriod);
	void stand(Vector2D pos, int inPeriod);

private:

	Timer timer;
	Vector2D startPosition, endPosition, position;
	Vector2D spaceInterval;
	int frames;
	int currentFrame;
	int *sequence;
	int standPeriod;
	int *timeInterval;
	bool started;
	bool ended;
	bool standing;

	void render(int posx, int posy);
};