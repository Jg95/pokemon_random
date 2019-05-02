#include "Enemy.h"


Enemy::Enemy():
	Pokemon(150, 72, 10, 31, 246 + 10, 31)
{
	groundMultiplyer = 1.75f;
	posData.x = 0;
}


Enemy::~Enemy(void)
{
}

bool Enemy::loadFromFile()
{
	bool success;

	if (!ground.loadFromFile("../img/Texturas/battle_base_wild_enemy.png"))
	{
		cout << "Failed to load ground texture image!" << endl;
		success = false;
	}

	if (!data.loadFromFile("../img/Texturas/healthbar_enemy.png"))
	{
		cout << "Failed to load data texture image!" << endl;
		success = false;
	}

	dexNum = 1 + rand() % 2;

	success = Pokemon::loadFromFile();

	return success;
}
