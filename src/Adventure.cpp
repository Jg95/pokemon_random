#include "Adventure.h"

Adventure::~Adventure()
{
}

bool Adventure::loadFromFile()
{
	for (int i = 0; i < 2; i++)
	{
		trainers += new Movable_Trainer(rand() % 19, rand() % 19);
		trainers[i].loadFromFile();
		trainers[i].setTrajectory(4, t);
	}

	route_0.loadFromFileT();
	//route_0.loadFromFile();
	if (!player.loadFromFile())
		return false;

	return true;
}

void Adventure::events(SDL_Event& e, bool& quit)
{

	//movement = Constants::STAND;

	if (e.type == SDL_QUIT)
	{
		quit = true;
	}
	else if (e.type == SDL_KEYDOWN)
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
			movement = Constants::UP;
			break;

		case SDLK_DOWN:
			movement = Constants::DOWN;
			break;

		case SDLK_LEFT:
			movement = Constants::LEFT;
			break;

		case SDLK_RIGHT:
			movement = Constants::RIGHT;
			break;

		default:
			movement = Constants::STAND;
			break;
		}
	if (movement != Constants::STAND)
	{
		if (!((player.getPos().x == route_0.getWidth() - 1 && movement == Constants::RIGHT) || (player.getPos().x == 0 && movement == Constants::LEFT) || (player.getPos().y == route_0.getHeight() - 2 && movement == Constants::DOWN) || (player.getPos().y == 0 && movement == Constants::UP)))
			player.move(movement);
		player.setBattleFlag(true);
	}
}

void Adventure::setCameraPos()
{
	cameraPos = player.getPos() - (sceneDim / 2);

	//Keep the camera in bounds
	if (cameraPos.x < 0)
		cameraPos.x = 0;

	if (cameraPos.y < 0)
		cameraPos.y = 0;

	if (cameraPos.x > route_0.getWidth() - sceneDim.x)
		cameraPos.x = route_0.getWidth() - sceneDim.x;

	if (cameraPos.y > route_0.getHeight() - sceneDim.y)
		cameraPos.y = route_0.getHeight() - sceneDim.y;

	//player.setRelPos(Vector2D(0, 0));

	if (cameraPos.x != 0 && cameraPos.x != route_0.getWidth() - sceneDim.x && (movement == Constants::RIGHT || movement == Constants::LEFT))
		player.setRelPos(cameraPos);

	if (cameraPos.y != 0 && cameraPos.y != route_0.getHeight() - sceneDim.y && (movement == Constants::DOWN || movement == Constants::UP))
		player.setRelPos(cameraPos);

	if ((cameraPos.x == route_0.getWidth() - sceneDim.x || cameraPos.x == 0) && (movement == Constants::RIGHT || movement == Constants::LEFT))
		player.Movable_Thing::setRelPos(cameraPos);

	if ((cameraPos.y == route_0.getHeight() - sceneDim.y || cameraPos.y == 0) && (movement == Constants::DOWN || movement == Constants::UP))
		player.Movable_Thing::setRelPos(cameraPos);
}

void Adventure::render()
{
	for (int i = 0; i < trainers.getNumber(); i++)
		Interaction::interaction(&trainers[i], &player);
	for (int i = 0; i < trainers.getNumber(); i++)
		for (int j = 0; j < route_0.getNumLayers(); j++)
		{
			if (i == 0)
				if (Interaction::interaction(route_0.getLayer(j), &player) == Constants::FIGHT)
					request = Constants::FIGHT;
			Interaction::interaction(route_0.getLayer(j), &trainers[i]);
		}		

	setCameraPos();
	//Render background
	route_0.printMap(-cameraPos.x, -cameraPos.y);
	//route_0.printSubMap(cameraPos.x, cameraPos.y, sceneDim.x, sceneDim.y);

	for (int i = 0; i < trainers.getNumber(); i++)
	{
		trainers[i].walk();
		trainers[i].setRelPos(cameraPos);
		trainers[i].animate();
	}

	player.animate();
}

void Adventure::close()
{
	//Free loaded images
	/*for (int i = 0; i < 5; i++)
		delete &trainers[i];*/
}


