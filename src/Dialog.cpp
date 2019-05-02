#include "Dialog.h"



Dialog::Dialog()
{
	for (int i = 0; i < 4; i++)
	{
		soption += new string;
		toption += new Texture;
	}
}

Dialog::~Dialog()
{
	free();
	toption.erase();
	soption.erase();
}

bool Dialog::loadFromFile()
{
	bool success = true;

	if (!menu.loadFromFile("../img/Texturas/menu3.png"))
	{
		cout << "Failed to load menu texture image!" << endl;
		success = false;
	}

	if (!info.loadFromFile("../img/Texturas/menu4.png"))
	{
		cout << "Failed to load info texture image!" << endl;
		success = false;
	}

	if (!cursor.loadFromFile("../img/Texturas/ball_small.png"))
	{
		cout << "Failed to load cursor texture image!" << endl;
		success = false;
	}

	return success;
}

void Dialog::render(int x, int y)
{
	menu.render(x, y);
	//info.render(x + menu.getWidth() - info.getWidth(), y);
	cursor.render(x + pcursor.x, y + pcursor.y);
	for (int i = 0; i < option.getNumber(); i++)
		toption[i].render(x + option[i].x + 10 + cursor.getWidth(), y + option[i].y);
}

void Dialog::free()
{
	menu.free();
	info.free();
	cursor.free();
	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].free();
}

void Dialog::events(Constants::FightState state, Vector2D posCursor, ListOf<Attack> attacks, float effectiveness)
{
	pcursor = posCursor;

	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].free();

	if (state == Constants::MAIN)
	{
		soption[0] = "Attack";
		soption[1] = "Pokemon";
		soption[2] = "Objects";
		soption[3] = "Escape";
	}

	if (state == Constants::ATTACK)
	{
		soption[0] = attacks[0].getName();
		soption[1] = attacks[1].getName();
		soption[2] = attacks[2].getName();
		soption[3] = attacks[3].getName();
	}

	if (state == Constants::NOT_IMPLEMENTED)
	{
		soption[0] = "Not Implemented";
		soption[1] = " ";
		soption[2] = " ";
		soption[3] = " ";
	}

	if (state == Constants::ATTACKING)
	{
		soption[0] = "Attacking";
		soption[1] = " ";
		if (effectiveness == 0.5f)
			soption[2] = "It's not very effective";
		if (effectiveness == 2.0f)
			soption[2] = "It's super effective";
		if (effectiveness == 1.0f)
			soption[2] = " ";
		soption[3] = " ";
	}

	if (state == Constants::DEFENDING)
	{
		soption[0] = "Defending";
		soption[1] = " ";
		if (effectiveness == 0.5f)
			soption[2] = "It's not very effective";
		if (effectiveness == 2.0f)
			soption[2] = "It's super effective";
		if (effectiveness == 1.0f)
			soption[2] = " ";
		soption[3] = " ";
	}

	for (int i = 0; i < toption.getNumber(); i++)
		toption[i].loadFromRenderedText(soption[i]);
}

void Dialog::updateOptions(ListOf<Vector2D> inoptions)
{
	option = inoptions;
}
