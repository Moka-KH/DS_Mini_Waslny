#include <iostream>
// #include "Wasalny.h"
#include <string>
#include <map>
#include <stack>
#include <climits>
#include <unordered_map>
#include <queue>
#include <utility> 
#include <vector>

using namespace std;


typedef pair<int, string> iPair;
const int INF = INT_MAX;
// create a vector to store the cities from the currentLocation to finalDistination
vector<string> path;


/**
 * Dijkstra's algorithm for finding the shortest path between two vertices in a graph.
 *
 * @param myMap A graphDS object representing the graph to search for the shortest path.
 * @param currentLocation The starting vertex for the shortest path search.
 * @param finalDistination The destination vertex for the shortest path search.
 *
 * @return The shortest distance from the starting vertex to the destination vertex.
 *         If the destination is unreachable, returns -1.
 *         The shortest path from the starting vertex to the destination vertex is stored in the path vector.
 */
int Dijkstra(graphDS myMap, string startingNode, string finalDistination) {

	//ipair determine the data types of the pair in the queue
	//vector<ipair> container for the priority queue
	//greater<ipair> cause the smallest element to appear as the top of the priority queue
	priority_queue<iPair, vector<iPair>, greater<iPair> > uncheckedVertices;

	int citiesNum = myMap.getVertexNum();

	// create a vector to store the distance from the source to any city 
	//use map instead of vectors because vector cann't deal with string keys
	map<string, int> shortestPath;


	//all the distances will be infinite or not determined
	unordered_map <string, list<pair <string, int>>>::iterator mapIterator;
	for (mapIterator = myMap.map.begin(); mapIterator != myMap.map.end(); mapIterator++)
		shortestPath.insert(make_pair(mapIterator->first, INF));


	//put the distance from the source to itself as 0 and push it into the queue to check the adj vertices
	shortestPath[startingNode] = 0;

	uncheckedVertices.push(make_pair(0, startingNode));

	//loop untill we check every node and determine the shortest path for each city 
	while (!uncheckedVertices.empty()) {

		//store the index of the vertix that has the minimum distance
		//the minimum distance it automatically allocated by the logic of priority queue
		string minDistCity = uncheckedVertices.top().second;

		// we will check its adj vertices now so we will pop it
		uncheckedVertices.pop();

		//create a list to store the adjacent cities of the minDistCity
		//we get the list from a function called getAdjacentList
		list<pair <string, int>> adjacentVertices;
		myMap.getAdjacentList(minDistCity, adjacentVertices);

		//create an iterator to iterate on the adjacent cities of the minDistCity
		list <pair <string, int>>::iterator listIterator;

		for (listIterator = adjacentVertices.begin(); listIterator != adjacentVertices.end(); listIterator++) {

			string cityName = listIterator->first;
			int weight = listIterator->second;

			//check if the path that I have in my array was greater than the new one ->update ,else don't change
			if (shortestPath[cityName] > shortestPath[minDistCity] + weight) {

				// Updating the shortest path of the city
				shortestPath[cityName] = shortestPath[minDistCity] + weight;
				//push the city in the array with its shortest path to check its adjacent later
				uncheckedVertices.push(make_pair(shortestPath[cityName], cityName));
			}
		}


	}

	// Check if the final destination is unreachable
	if (shortestPath[finalDistination] == INF) {
		return -1;
	}

	else {
		//store the final distination index in the list
		string current = finalDistination;
		path.push_back(current);

		// Backtrack from the destination to the source to get the shortest path
		while (current != startingNode) {

			list<pair <string, int>> adjacentVertices;
			myMap.getAdjacentList(current, adjacentVertices);
			list <pair <string, int>>::iterator listIterator;
			for (listIterator = adjacentVertices.begin(); listIterator != adjacentVertices.end(); listIterator++) {

				string adjVertex = listIterator->first;
				int weight = listIterator->second;
				if (shortestPath[current] == shortestPath[adjVertex] + weight) {
					current = adjVertex;
					path.push_back(current);
					break;
				}
			}

		}
		reverse(path.begin(), path.end());

		// Return the shortest path from the source to the destination
		return shortestPath[finalDistination];
	}
}