#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>

using std::cin;
using std::cout;

class Program
{
private:
	int width;
	int height;
	char** map;

	void loadMap();
	void drawMap();

public:
	Program();
	~Program();

	void start();
};

#endif