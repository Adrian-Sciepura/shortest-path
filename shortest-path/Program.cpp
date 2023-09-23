#include "Program.h"

void Program::loadMap()
{
    for (int city = 0; city < cities.SIZE; city++)
    {
        cities.data[city] = nullptr;
    }

	cin >> width >> height;
	map = new MapElement*[height];
	char key = NULL;
	for (int i = 0; i < height; i++)
	{
		map[i] = new MapElement[width];
		for (int j = 0; j < width; j++)
		{
			key = getchar();
			if(key == '\n')
				key = getchar();

			map[i][j].type = key;
			map[i][j].visited = false;
			map[i][j].prev = nullptr;
		}
	}
}

void Program::drawMap()
{
	for (int i = 0; i < height; i++)
	{
		cout << "\n";
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j].type;
		}
	}
}

void Program::loadCities()
{
	City* city = nullptr;
	String cityName;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j].type == '*')
			{
				cityName = loadCityName(i, j);
				
				cities[cityName] = new City();
				city = cities[cityName];
				city->name = cityName;
				city->x = i;
				city->y = j;
				city->bVisited = false;
				city->distance = INFINITY;
				city->parent = nullptr;
			}
		}
	}
}

String Program::loadCityName(int x, int y)
{
	int nameX = 0;
	int nameY = 0;

	for (int i = x - 1; i <= x + 1; i++)
	{
		if (i < 0 || i >= height)
			continue;
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (j < 0 || j >= width)
				continue;

			if (map[i][j].type > '.')
			{
				nameX = i;
				nameY = j;
			}
		}
	}

	for (int i = nameY; i > 0; i--)
	{
		if (map[nameX][nameY - 1].type > '.')
			nameY--;
		else
			break;
	}

	int bufferLength = 0;
	for (int i = nameY; i < width; i++)
	{
		if (map[nameX][i].type <= '.')
			break;
		buffer[bufferLength] = map[nameX][i].type;
		bufferLength++;
	}

	buffer[bufferLength] = '\0';
	return String(buffer);
}

void Program::loadCityConnections()
{
	for (int city = 0; city < cities.SIZE; city++)
	{
        if (cities.data[city] == nullptr)
            continue;

		int currX = cities.data[city]->x;
		int currY = cities.data[city]->y;
		int newX = 0;
		int newY = 0;
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			newX = currX + directions[i].first;
			newY = currY + directions[i].second;
			if (newX < 0 || newX >= height || newY < 0 || newY >= width || (map[newX][newY].type != '#' && map[newX][newY].type != '*'))
				count++;
		}

		if (count == 4)
			continue;

		Queue<Pair<int, int>> queue;

		queue.push({ currX, currY });
		map[currX][currY].visited = true;

		while (!queue.empty())
		{
			currX = queue.front().first;
			currY = queue.front().second;
			queue.pop();


			for (int i = 0; i < 4; i++)
			{
				newX = currX + directions[i].first;
				newY = currY + directions[i].second;
				if (newX < 0 || newX >= height || newY < 0 || newY >= width)
					continue;
				if (map[newX][newY].visited)
					continue;
				if (map[newX][newY].type >= '.')
					continue;
				
				map[newX][newY].visited = true;
				map[newX][newY].prev = &map[currX][currY];

				if (map[newX][newY].type == '#')
				{
					queue.push({ newX, newY });
				}
				else if (map[newX][newY].type == '*')
				{
					String cityName = loadCityName(newX, newY);
					City* endCity = cities[cityName];
                    cities.data[city]->neighbours.push_front({ endCity, getConnection(endCity) });
				}
			}
		}

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
			{
				map[i][j].visited = false;
				map[i][j].prev = nullptr;
			}
	}
}

int Program::getConnection(City* end)
{
	int counter = 0;
	MapElement* element = &map[end->x][end->y];
	while (element != nullptr)
	{
		counter++;
		element = element->prev;
	}

	return counter-1;
}

void Program::loadAirports()
{
	int numberOfAirports = 0;
	cin >> numberOfAirports;

	City* city1 = nullptr;
	City* city2 = nullptr;
	int length = 0;
	for (int i = 0; i < numberOfAirports; i++)
	{
		city1 = cities[getString()];
		city2 = cities[getString()];
		cin >> length;
		city1->neighbours.push_front({ city2, length });
	}
}

void Program::runQueries()
{
	int numberOfQueries = 0;
	cin >> numberOfQueries;
	String city1;
	String city2;
	char buffer[20];
	int mode = 0;
	for (int i = 0; i < numberOfQueries; i++)
	{
		cin >> buffer;
		city1 = buffer;
		cin >> buffer;
		city2 = buffer;
		cin >> mode;

		find(cities[city1], cities[city2], mode);
	}
}

void Program::find(City* start, City* end, int mode)
{
    for (int city = 0; city < cities.SIZE; city++)
    {
        if(cities.data[city] == nullptr)
            continue;
     
        cities.data[city]->distance = INT_MAX;
        cities.data[city]->parent = nullptr;
    }

    PriorityQueue<Pair<int, City*>> pq;

	pq.push({0, start});
	start->distance = 0;
	while (!pq.empty()) {
        City* u = pq.top().second;
		pq.pop();

		ListNode<Pair<City*, int>>* curr = u->neighbours.first;
		while (curr != nullptr)
		{
			City* v = curr->data.first;
			int weight = curr->data.second;

			if (v->distance > u->distance + weight)
			{
				v->distance = u->distance + weight;
				v->parent = u;
                pq.push({ v->distance, v });
			}

			curr = curr->next;
		}
	}

	std::cout << end->distance;
	if (mode == 1) {
		Stack<City*> stack;
		City* c = end;
		while (c != nullptr)
		{
			stack.push(c);
			c = c->parent;
		}
		if (stack.size() >= 1)
			stack.pop();
		while (stack.size() > 1)
		{
			cout << ' ' << stack.top()->name;
			stack.pop();
		}
	}
	cout << '\n';
}

String Program::getString()
{
	char c = NULL;
	int index = 0;
	while (true)
	{
		c = getchar();
		if(c == '\n')
			continue;
		if (c == ' ')
			break;

		buffer[index] = c;
		index++;
	}
	buffer[index] = '\0';
	return String(buffer);
}

Program::Program()
{
	directions[0] = { 0, -1 };
	directions[1] = { 0, 1 };
	directions[2] = { -1, 0 };
	directions[3] = { 1, 0 };

	numberOfCities = 0;
}

Program::~Program()
{
	for (int i = 0; i < height; i++)
	{
		delete[] map[i];
	}
	delete[] map;

    for(int city = 0; city < cities.SIZE; city++)
	{
		delete cities.data[city];
	}
}

void Program::start()
{
	loadMap();
	loadCities();
	loadCityConnections();
	loadAirports();
	runQueries();
}