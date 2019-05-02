#include "Movable_Thing.h"

Movable_Thing::Movable_Thing()
{
}

Movable_Thing::~Movable_Thing()
{
}

bool Movable_Thing::loadFromFile()
{
	if (!animation[Constants::KEY_PRESS_DIRECTION_DOWN].loadFromFile("../img/player/player_down_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_DOWN].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_UP].loadFromFile("../img/player/player_up_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_UP].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_UP].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_LEFT].loadFromFile("../img/player/player_left_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_LEFT].setPosition(position*Constants::TILE_DIM);

	if (!animation[Constants::KEY_PRESS_DIRECTION_RIGHT].loadFromFile("../img/player/player_right_anim2.png"))
		return false;
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setClips(nclipsX, nclipsY, xvec, yvec, wvec, hvec);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setSequence(dim, sequence, timeInterval);
	animation[Constants::KEY_PRESS_DIRECTION_RIGHT].setPosition(position*Constants::TILE_DIM);

	if (!tallGrass.loadFromFile("../img/sprites/wild_grass_small.png"))
		return false;

	return true;
}

bool Movable_Thing::loadFromSprite(Sprite sprite)
{
	return true;
}

bool Movable_Thing::move(Constants::Orientation inOrientation)
{
	if (animation[inOrientation].isEnded() && animation[orientation].isEnded())
	{
		orientation = inOrientation;
		prevPos = position;

		switch (orientation)
		{
		case Constants::DOWN:
			position.y++;
			break;
		case Constants::UP:
			position.y--;
			break;
		case Constants::LEFT:
			position.x--;
			break;
		case Constants::RIGHT:
			position.x++;
			break;
		default:
			break;
		}
		animation[orientation].start();
		return true;
	}
	return false;
}

void Movable_Thing::animate()
{
	if (animation[orientation].isEnded())
	{
		animation[orientation].hold();
		if (flagTallGrass)
		{
			renderTallGrass();
			flagTallGrass = false;
		}
	}
	else
	{
		animation[orientation].animate();
		/*if (flagTallGrass)
		{
			renderTallGrass();
			flagTallGrass = false;
		}*/
	}
}

void Movable_Thing::animate(Vector2D pos)
{
	if (animation[orientation].isEnded())
		animation[orientation].hold(pos*Constants::TILE_DIM);
	else
		animation[orientation].animate(pos*Constants::TILE_DIM);
}

void Movable_Thing::renderTallGrass()
{
	tallGrass.render((position.x - camPos.x) * Constants::TILE_DIM, (position.y - camPos.y) * Constants::TILE_DIM + Constants::TILE_DIM/2 + 5);
}

void Movable_Thing::setRelPos(Vector2D pos)
{
	camPos = pos;
	animation[orientation].setSpaceInterval((prevPos - camPos)*Constants::TILE_DIM, (position - camPos)*Constants::TILE_DIM);
}

void Movable_Thing::setPos(Vector2D pos)
{
	position = pos;
	animation[orientation].setSpaceInterval((prevPos - camPos)*Constants::TILE_DIM, (position - camPos)*Constants::TILE_DIM);
}
