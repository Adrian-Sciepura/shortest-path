#include "Program.h"

Program::Program() : width(0), height(0), map(nullptr)
{
}

Program::~Program()
{
	if (map != nullptr)
	{
		for (int i = 0; i < height; i++)
		{
			delete[] map[i];
		}
		delete[] map;
	}
}

void Program::loadMap()
{
	cin >> width >> height;
	map = new char*[height];
	for (int i = 0; i < height; i++)
	{
		map[i] = new char[width];
		for (int j = 0; j < width; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Program::drawMap()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void Program::start()
{
	loadMap();

	std::cout << "\n\n\n\n\n";

	drawMap();
}
