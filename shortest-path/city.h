#ifndef CITY_H
#define CITY_H

#include "String.h"
#include "List.h"
#include "Pair.h"

struct City
{
	int x, y;
	bool bVisited;
	int distance;
	City* parent;
	String name;
	List<Pair<City*, int>> neighbours;
};

#endif