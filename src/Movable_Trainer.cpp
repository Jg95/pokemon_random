#include "Movable_Trainer.h"

Movable_Trainer::Movable_Trainer(): trajIndex(0), trajDim(0)
{
}

Movable_Trainer::~Movable_Trainer()
{
}

void Movable_Trainer::setSprite()
{

}

void Movable_Trainer::setTrajectory(int dim, Constants::Orientation *t)
{
	trajDim = dim;
	trajectory = t;
}

void Movable_Trainer::walk()
{
	if (trajIndex == trajDim)
		trajIndex = 0;
	if (trajectory[trajIndex] == Constants::STAND)
	{
		if (animation[orientation].isEnded())
		{
			animation[orientation].stand(16 * period);
			trajIndex++;
		}
	}
	else
		if (move(trajectory[trajIndex]))
			trajIndex++;
}

