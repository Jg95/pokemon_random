#pragma once

#include <iostream>
#include "Constants.h"
#include "Text_Manager.h"

using namespace std;

class Attack
{
	int id;
	string name;

	//STATS
	int power;
	Constants::Types type;

	static Text_Manager attackList;
public:
	//CONSTRUCTION - DESTRUCTION
	Attack(int inId);
	~Attack(void);

	void loadStats();

	//INTERFACE INLINE METHODS
	int getPower(){return power;}
	string getName() { return name; }
	Constants::Types getType() { return type; }
};

