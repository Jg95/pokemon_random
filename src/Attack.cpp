#include "Attack.h"


Attack::Attack(int inId):
	id(inId)
{
}


Attack::~Attack(void)
{
}

void Attack::loadStats()
{
	name = attackList.getData(id, 0);
	type = attackList.getType(id, 1);
	power = attackList.getDataInt(id, 2);
}

Text_Manager Attack::attackList("../data/Attacks.txt", Constants::NUM_ATTKS, Constants::NUM_STATS_ATTKS);
