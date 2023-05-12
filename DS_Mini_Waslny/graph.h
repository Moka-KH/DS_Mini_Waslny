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
	string name;

	// unordered_map (hash table) storing all data we have
	// key: city name - value: linked list of the connected vertices
	// each list element is a pair of 2 values:
	// name of adjacent city - the distance between it and the original vertex
	unordered_map <string, list<pair <string, float>>> map;

	pair <string, float> pairHolder;

	graph();
	graph(string);
	~graph();

	int addCity(string newCity);
	int addCity(string newCity, string adjCity, float distance);
	int addRoad(string city1, string city2, float distance);
	void deleteEdge(string city1, string city2);

	int deleteCity(string cityName);
	int deleteRoad(string city1, string city2);

	int getVertexNum();
	void setVertexNum(int);
	int getEdges(string city1);

	void display();
	//Dina and Mayar
	list<pair <string, float>> getOutAdjacent(string city);
	list<pair <string, float>> getInAdjacents(string city);
	list<pair <string, float>> getAdjacentVertices(string city);
	bool checkCity(string city);
	bool checkEdge(string city1,string city2);
	float getEdgeWieght(string city1, string city2);
	/*void writeGraphToFile(graph& g, const string& filename);
	void readGraphFromFile(graph& g, const string& filename);*/

};