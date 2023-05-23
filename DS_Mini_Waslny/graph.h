#pragma once
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <list>
#include <map>

using namespace std;

class graph
{
private:
	int vertexNum;
	int edgeNum;
	void deleteEdge(string city1, string city2);

public:
	/*
	* unordered_map(hash table) storing the map data
	* key: city name - value: linked list of the connected vertices
	* each list element is a pair of 2 values:
	* name of adjacent city - the distance from the vertex to this adjacent
	*/
	unordered_map <string, list<pair <string, float>>> map;
	string name;

	// Constructors & Destructor
	graph();
	graph(string);
	~graph();

	// Getters
	int getVertexNum();
	int getEdgeNum();
	int getOutEdgesNumber(string city1);
	float getEdgeWieght(string city1, string city2);

	list<pair <string, float>> getOutAdjacents(string city);
	list<pair <string, float>> getInAdjacents(string city);
	list<pair <string, float>> getAdjacents(string city);

	// Cities
	int addCity(string city);
	int deleteCity(string cityName);

	// Roads
	int addEditRoad(string city1, string city2, float distance);
	int deleteRoad(string city1, string city2);

	// Boolean Checkers
	bool vertexExists(string city);
	bool edgeExists(string city1,string city2);
	bool empty();

	void display();
};