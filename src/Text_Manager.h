#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "Constants.h"

using namespace std;

class Text_Manager
{
public:
	Text_Manager(const string inName, int maxLn, int maxCol);
	~Text_Manager();

	bool find(const string w);
	void loadData(int Ln, int Col);
	string getData(int Ln, int Col) { return data[Ln][Col]; }
	void getLineInt(int Ln, int* aux);
	int getDataInt(int Ln, int Col) { return stoi(data[Ln][Col]); }
	Constants::Types getType(int Ln, int Col);

private:
	ifstream file;
	const string name;
	string data[10][10];

	const int maxLn;
	const int maxCol;
};

