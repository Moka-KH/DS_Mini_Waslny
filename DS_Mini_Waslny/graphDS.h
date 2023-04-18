#include <unordered_map>
#include <list>
#include <vector>
#include <string>

using namespace std;

class graphDS
{
public:


	//holds the original vertex and the list of vertices connected to the original vertex
	unordered_map < string, list<pair <string, int>>> map;

	//the list element consists of 2 values -> name of adjacent city and the distance between it and the original vertex
	pair <string, int> listPair;

	//itrators for Map and List
	unordered_map< string, list<pair <string, int>>>::iterator itrMap;
	list < pair <string, int>> ::iterator itrList;

	
	void addCity(string newCity);

	void addCity(string newCity, string adjCity, int distance);
	void addEdge(string newCity, string adjCity, int distance);
	void display();
	~graphDS();
};

