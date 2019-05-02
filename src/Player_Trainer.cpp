#include "Player_Trainer.h"

Player_Trainer::Player_Trainer(void)
{
}

Player_Trainer::~Player_Trainer(void)
{
}

void Player_Trainer::setRelPos(Vector2D pos)
{
	camPos = pos;
	animation[orientation].setSpaceInterval((position-camPos)*Constants::TILE_DIM, (position - camPos)*Constants::TILE_DIM);
}

