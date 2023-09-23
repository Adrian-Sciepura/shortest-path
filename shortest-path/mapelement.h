#ifndef MAP_ELEMENT_H
#define MAP_ELEMENT_H

struct MapElement
{
	bool visited;
	char type;
	MapElement* prev;
};

#endif