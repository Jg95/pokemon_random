#pragma once
class Constants
{
public:
	Constants();
	~Constants();

	//The dimensions of the level
	static const int LEVEL_WIDTH = 1280;
	static const int LEVEL_HEIGHT = 960;

	//Screen dimension constants
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	static const int DIM = 400;

	static const int PLAYER_WIDTH = 96;
	static const int PLAYER_HEIGHT = 96;

	static const int TILE_DIM = 64;

	//DYMENSIONS OF FILES MATRIX
	static const int NUM_PKMN_DEX = 3;
	static const int NUM_STATS_DEX = 6;
	static const int NUM_ATTKS = 8;
	static const int NUM_STATS_ATTKS = 3;
	static const int NUM_PKMN_STATE = 2;
	static const int NUM_STATS_STATE = 8;

	enum State
	{
		START_SCREEN,
		ADVENTURE,
		FIGHT,
		TRANSITION,
		STATE_TOTAL
	};

	enum Orientation
	{
		DOWN,
		UP,
		LEFT,
		RIGHT,
		ORIENTATION_TOTAL,
		STAND
	};

	enum KeyPressDirection
	{
		KEY_PRESS_DIRECTION_DOWN,
		KEY_PRESS_DIRECTION_UP,
		KEY_PRESS_DIRECTION_LEFT,
		KEY_PRESS_DIRECTION_RIGHT,
		KEY_PRESS_DIRECTION_TOTAL,
		KEY_PRESS_DIRECTION_DEFAULT
	};

	enum LayerType
	{
		WALKABLE,
		WATER,
		TALLGRASS,
		NOTWALKABLE,
		ENTRANCE,
		TOTAL_LAYERS
	};

	enum Types {
		FLYING,
		FIGHTING,
		ROCK,
		TOTAL_TYPES,
		DEFAULT_TYPE
	};

	enum FightState {
		MAIN,
		ATTACK,
		ATTACKING,
		DEFENDING,
		NOT_IMPLEMENTED,
		TOTAL_FIGHT_STATES
	};
};

