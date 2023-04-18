#include <iostream>
#include <string.h>
#include <unordered_map>
#include <list>

using namespace std;

class graphDS
{
public:


	//holds the original vertex and the list of vertices connected to the original vertex
	unordered_map < string, list<pair <string, int>>> map;

	//the list element consists of 2 values -> name of adjacent city and the distance between it and the original vertex
	pair <string, int> pairHolder;

	//itrators for Map and List
	unordered_map< string, list<pair <string, int>>>::iterator mapIterator;
	list < pair <string, int>> ::iterator itrList;

	
	void addCity(string newCity);

	void addCity(string newCity, string adjCity, int distance);
	void addRoad(string city1, string city2, int distance);
	void deleteCity(string cityName);
	void deleteRoad(string city1, string city2);
	void display();
	~graphDS();
};

