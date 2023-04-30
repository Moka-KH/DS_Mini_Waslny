#pragma once
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <list>


using namespace std;

class graph
{
private:
	int vertexNum;

public:

	// unordered_map (hash table) storing all data we have
	// key: city name - value: linked list of the connected vertices
	// each list element is a pair of 2 values:
	// name of adjacent city - the distance between it and the original vertex
	unordered_map <string, list<pair <string, int>>> map;

	pair <string, int> pairHolder;

	// itrators for Map and List
	unordered_map <string, list<pair <string, int>>>::iterator mapIterator;
	list <pair <string, int>>::iterator listIterator;

	graph();
	~graph();

	void addCity(string newCity);
	void addCity(string newCity, string adjCity, int distance);
	void addRoad(string city1, string city2, int distance);

	void deleteCity(string cityName);
	void deleteRoad(string city1, string city2);

	int getVertexNum();
	void getAdjacentList(string city, list<pair <string, int>>& adj);
	void display();
};