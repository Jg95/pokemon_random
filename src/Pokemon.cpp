#include "Pokemon.h"

//CONSTRUCTION - DESTRUCTION
Pokemon::Pokemon(int xHP, int yHP, int xName, int yName, int xLv, int yLv):
	HP(xHP, yHP),
	pName(xName, yName),
	pLv(xLv, yLv)
{
	width = 0;
	height = 0;
	srand(time(NULL));
}


Pokemon::~Pokemon(void)
{
	attacks.erase();
}

//MEDIA METHODS
bool Pokemon::loadFromFile()
{
	bool success = true;
	loadStats();

	//cout << pathBody << endl;

	if (!body.loadFromFile(pathBody))
	{
		cout<<"Failed to load body texture image!"<<endl;
		success = false;
	}

	if (!name.loadFromRenderedText(sName))
	{
		cout<<"Failed to load name texture from text!"<<endl;
		success = false;
	}

	if (!tLv.loadFromRenderedText(sLv))
	{
		cout<<"Failed to load level texture from text!"<<endl;
		success = false;
	}

	width = ground.getWidth();
	height = body.getHeight();

	return success;
}

void Pokemon::render(int x, int y)
{
	//Pokemon render
	ground.render(x, (int)(y + height - ground.getHeight()/groundMultiplyer));
	body.render(x + width/2 - body.getWidth()/2, y);

	//Data render
	posData.y = y + 10;
	data.render(posData.x, posData.y);

	//Health render
	float relativeHP = (float) currentHP / maxHP;
	SDL_Rect hp = {posData.x + HP.x, posData.y + HP.y, (int)(144 * relativeHP), 9};
	if (relativeHP >= 0.5f)
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	if (relativeHP >= 0.25f && relativeHP < 0.5f)
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0x00, 0xFF);
	if (relativeHP < 0.25f)
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &hp);
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Text render
	name.render(posData.x + pName.x, posData.y + pName.y);
	tLv.render(posData.x + pLv.x, posData.y + pLv.y);
}

void Pokemon::free()
{
	ground.free();
	body.free();
	data.free();
	name.free();
	tLv.free();
}

void Pokemon::loadStats()
{
	sName = pokedex.getData(dexNum, 0);
	type = pokedex.getType(dexNum, 1);
	maxHP = pokedex.getDataInt(dexNum, 2);
	attack = pokedex.getDataInt(dexNum, 3);
	defence = pokedex.getDataInt(dexNum, 4);
	pathBody = pokedex.getData(dexNum, 5);

	for (int i = 0; i < 4; i++)
	{
		if (attackId[i] != -1)
		{
			attacks += new Attack(attackId[i]);
			attacks[attacks.getNumber() - 1].loadStats();
		}
	}

	sLv = to_string(Lv);
	if (currentHP == -1)
		currentHP = maxHP;
	//cout << dexNum << sName << endl;
}

void Pokemon::setData(int d[])
{
	dexNum = d[1];
	Lv = d[2];
	currentHP = d[3];
	for (int i = 0; i < 4; i++)
		attackId[i] = d[i + 4];
}

float Pokemon::attacking(Pokemon& p, Attack a)
{
	float stab = 1.0f;
	if (type == a.getType())
		stab = 1.5f;

	float effectiveness = 1.0f;
	if ((a.getType() == Constants::FLYING && p.type == Constants::FIGHTING) || (a.getType() == Constants::FIGHTING && p.type == Constants::ROCK) || (a.getType() == Constants::ROCK && p.type == Constants::FLYING))
		effectiveness = 2.0f;
	if ((a.getType() == Constants::FLYING && p.type == Constants::ROCK) || (a.getType() == Constants::ROCK && p.type == Constants::FIGHTING) || (a.getType() == Constants::FIGHTING && p.type == Constants::FLYING))
		effectiveness = 0.5f;

	float random = 85 + rand() % (100 + 1 - 85);

	p.currentHP -= (int)(0.01f * random * stab * effectiveness * ((0.2 * Lv + 1) * attack * a.getPower() / 25 / p.defence + 2));
	if (p.currentHP <= 0)
	{
		updateHP();
		p.updateHP();
		effectiveness = -1.0f;
	}

	return effectiveness;
}

Text_Manager Pokemon::pokedex("../data/Pokedex.txt", Constants::NUM_PKMN_DEX, Constants::NUM_STATS_DEX);
