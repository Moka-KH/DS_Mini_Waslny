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
	int edgeNum;
	void deleteEdge(string city1, string city2);

public:
	string name;

	// unordered_map (hash table) storing all data we have
	// key: city name - value: linked list of the connected vertices
	// each list element is a pair of 2 values:
	// name of adjacent city - the distance between it and the original vertex
	unordered_map <string, list<pair <string, float>>> map;

	graph();
	graph(string);
	~graph();

	int addCity(string city);
	int addCity(string newCity, string adjCity, float distance);
	int addRoad(string city1, string city2, float distance);

	void deleteCity(string cityName);
	void deleteRoad(string city1, string city2);

	int getVertexNum();
	int getEdgeNum();

	void display();
	list<pair <string, float>> getOutAdjacents(string city);
	list<pair <string, float>> getInAdjacents(string city);
	list<pair <string, float>> getAdjacents(string city);
	int outEdgesNumber(string city1);
	bool vertexExists(string city);
	bool edgeExists(string city1,string city2);
	float EdgeWieght(string city1, string city2);
	bool emptyGraph();
};