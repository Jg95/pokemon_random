#include "Text_Manager.h"

Text_Manager::Text_Manager(const string inName, int inmaxLn, int inmaxCol): 
	name(inName),
	maxLn(inmaxLn),
	maxCol(inmaxCol)
{
	loadData(maxLn, maxCol);
}


Text_Manager::~Text_Manager()
{
}

bool Text_Manager::find(const string w)
{
	string line;
	file.open(name, ios::in);

	if (file.is_open())
		while (getline(file, line))
		{
			if (!w.compare(line)) return true;		
		}

	else cout << "Error al abrir fichero\n";

	file.close();
	return false;
}

void Text_Manager::loadData(int Ln, int Col)
{
	string line;
	file.open(name, ios::in);

	if (file.is_open())
		for (int i = 0; i < Ln; i++)
		{
			getline(file, line);
			for (int j = 0; j < Col; j++)
				file >> data[i][j];
		}
	else cout << "Error al abrir fichero\n";

	file.close();
}

Constants::Types Text_Manager::getType(int Ln, int Col)
{
	int type = getDataInt(Ln, Col);
	if (type == 0)
		return Constants::FLYING;
	if (type == 1)
		return Constants::FIGHTING;
	if (type == 2)
		return Constants::ROCK;

	return Constants::DEFAULT_TYPE;
}

void Text_Manager::getLineInt(int Ln, int* aux)
{
	for (int i = 0; i < maxCol; i++)
		aux[i] = stoi(data[Ln][i]);
}