#include "Interaction.h"

Interaction::Interaction()
{
}

Interaction::~Interaction()
{
}

void Interaction::interaction(Layer* l, Movable_Thing* t)
{
	if(l->getTile(t->getPos()))
		switch (l->getType())
		{
		case Constants::WATER:
		case Constants::NOTWALKABLE:
			t->setPos(t->getPrevPos());
			break;
		case Constants::TALLGRASS:
			t->setRenderTallGrass();
			break;
		case Constants::ENTRANCE:
			t->setRenderTallGrass();
			break;
		//case Constants::WATER:
		//	dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
		//	break;
		default:
			break;
		}
}

Constants::State Interaction::interaction(Layer* l, Player_Trainer* t)
{
	static bool flag = true;
	if (flag)
	{
		flag = false;
		srand(time(NULL));
	}

	int randNum;
	if (l->getTile(t->getPos()))
		switch (l->getType())
		{
		case Constants::WATER:
			dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
		case Constants::NOTWALKABLE:
			t->setPos(t->getPrevPos());
			break;

		case Constants::TALLGRASS:
			t->setRenderTallGrass();
			randNum = rand() % 100 + 1;
			if (t->getBattleFlag())
			{
				t->setBattleFlag(false);
				if (randNum > 99)
					return Constants::FIGHT;
			}
			break;

		case Constants::ENTRANCE:
			t->setRenderTallGrass();
			break;

			//case Constants::WATER:
			//	dynamic_cast<Player_Trainer*>(t)->swimmingRequest();
			//	break;

		default:
			break;
		}

	return Constants::ADVENTURE;
}

void Interaction::interaction(Movable_Thing* t, Player_Trainer* p)
{
	if (t->getPos() == p->getPos())
		p->setPos(p->getPrevPos());
}