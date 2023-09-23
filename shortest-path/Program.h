#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>

#include "MapElement.h"
#include "City.h"
#include "List.h"
#include "String.h"
#include "Pair.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "HashTable.h"

using std::cout;
using std::cin;

class Program
{
private:
	int width;
	int height;
	int numberOfCities;
	MapElement** map;
    HashTable<City*> cities;
    char buffer[15];
	Pair<int, int> directions[4];

	void loadMap();
	void drawMap();

	void loadCities();
	String loadCityName(int x, int y);
	void loadCityConnections();
	int getConnection(City* end);

	void loadAirports();
	void runQueries();

	void find(City* start, City* end, int mode);
	String getString();

public:
	Program();
	~Program();

	void start();
};

#endif