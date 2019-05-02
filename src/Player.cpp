#include "Player.h"

//CONSTRUCTION - DESTRUCTION
Player::Player():
	//Render, HP, Name and Level positions
	Pokemon(216, 75, 60, 33, 312+10, 33),
	pcurrentHP(210, 92),
	pmaxHP(286+10, 92)
{
	groundMultiplyer = 1;
}


Player::~Player(void)
{
}

//GRAPHIC METHODS
bool Player::loadFromFile()
{
	bool success;

	if (!ground.loadFromFile("../img/Texturas/battle_base_wild_player.png"))
	{
		cout << "Failed to load ground texture image!" << endl;
		success = false;
	}

	if (!data.loadFromFile("../img/Texturas/healthbar_player.png"))
	{
		cout << "Failed to load data texture image!" << endl;
		success = false;
	}

	success = Pokemon::loadFromFile();
	updateXData();

	smaxHP = to_string(maxHP);
	scurrentHP = to_string(currentHP);

	if (!tmaxHP.loadFromRenderedText(smaxHP))
	{
		cout<<"Failed to load maxHP texture from text!"<<endl;
		success = false;
	}

	if (!tcurrentHP.loadFromRenderedText(scurrentHP))
	{
		cout<<"Failed to load currentHP texture from text!"<<endl;
		success = false;
	}

	return success;
}

void Player::render(int x, int y)
{
	smaxHP = to_string(maxHP);
	scurrentHP = to_string(currentHP);

	tmaxHP.loadFromRenderedText(smaxHP);
	tcurrentHP.loadFromRenderedText(scurrentHP);

	Pokemon::render(x, y);
	
	tcurrentHP.render(posData.x + pcurrentHP.x, posData.y + pcurrentHP.y);
	tmaxHP.render(posData.x + pmaxHP.x, posData.y + pmaxHP.y);
}

void Player::free()
{
	Pokemon::free();
	tcurrentHP.free();
	tmaxHP.free();
}

void Player::updateXData()
{
	posData.x = Constants::SCREEN_WIDTH - data.getWidth();
}
