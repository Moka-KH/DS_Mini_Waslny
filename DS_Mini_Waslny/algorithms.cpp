#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <stack>
#include <climits>
#include "graph.h"
#include "algorithms.h"

using namespace std;

/**
* DFS - Traverses the graph and prints the vertices values
* @graph: the graph object to traverse
* @startVertex: the vertex to start applying the algorithm from
* 
* Return: nothing
*/
void DFS(graph& graph, string startVertex)
{
	unordered_map<string, bool> visited;

	// initialize the "visited" map to be all unvisited
	for (auto& x : graph.map)
		visited[x.first] = false;

	stack<string> NodesToCheckNeighbors;

	// visited means the node was put in the stack
	visited[startVertex] = true;
	NodesToCheckNeighbors.push(startVertex);

	while (!NodesToCheckNeighbors.empty())
	{
		string currentNode = NodesToCheckNeighbors.top();

		// the action to do on the vertex (here we print)
		cout << currentNode << endl;
		NodesToCheckNeighbors.pop();

		// get the adjacency list of the current vertex
		list<pair<string, float>> adjacencyList;
		graph.getAdjacentList(currentNode, adjacencyList);

		// iterate over the adjacent vertices of temp
		for (auto& it : adjacencyList)
		{
			// if you find a node that is not visited
			if (!visited[it.first])
			{
				// push it to the stack
				NodesToCheckNeighbors.push(it.first);
				// and mark it as visited
				visited[it.first] = true;
			}
		}
	}
	cout << "End of Vertices" << endl;
	// if you wish, print the isolated vertices
}

// ================================================================================

typedef pair<float, string> iPair;
const float INFINITE = INT_MAX;
// create a vector to store the cities from the currentLocation to finalDistination
vector<string> path;

/**
 * Dijkstra's algorithm for finding the shortest path between two vertices in a graph.
 *
 * @param myMap A graphDS object representing the graph to search for the shortest path.
 * @param currentLocation The starting vertex for the shortest path search.
 * @param finalDistination The destination vertex for the shortest path search.
 * @param totalDistance The shortest distance between the two cities 
 *
 * @return The shortest path vector from the starting vertex to the destination vertex.
 *     
 */
float Dijkstra(graph& myMap, string startingNode, string finalDistination, vector<string>& path) {

	/*
	greater<ipair> makes the queue uses the minimum heap data structure(binary tree)
	which puts the smallest element at the top of the queue
	*/
	priority_queue<iPair, vector<iPair>, greater<iPair> > uncheckedVertices;

	float totalDistance;
	int citiesNum = myMap.getVertexNum();

	// shortestPaths is a map that stores the distance from the starting city to any city
	// (the table row in video)
	map<string, float> shortestPaths;


	// set all shortest paths to infinity
	unordered_map <string, list<pair <string, float>>>::iterator mapIterator;
	for (mapIterator = myMap.map.begin(); mapIterator != myMap.map.end(); mapIterator++)
		shortestPaths.insert(make_pair(mapIterator->first, INFINITE));


	// put the distance from the source to itself as 0
	shortestPaths[startingNode] = 0;
	// and push it into the queue to check its adjacent vertices
	uncheckedVertices.push(make_pair(0, startingNode));

	// Determine the shortest path for each city 
	while (!uncheckedVertices.empty())
	{
		// the city name with the minimum distance till now (the priority queue top)
		string minDistCity = uncheckedVertices.top().second;

		// I stored its name so, Pop it
		uncheckedVertices.pop();

		// store the its adjacent cities in a list
		list<pair <string, float>> adjacentVertices;
		myMap.getAdjacentList(minDistCity, adjacentVertices);

		// an iterator for this list
		list <pair <string, float>>::iterator listIterator;

		// iterate over this list to find a better path
		for (listIterator = adjacentVertices.begin(); listIterator != adjacentVertices.end(); listIterator++) {

			string cityName = listIterator->first;
			float weight = listIterator->second;

			//check if the path that I have in my array was greater than the new one ->update ,else don't change
			// if the node at which I'm pointing at this iteration is a better path
			// (the path from the preceding node 
			if (shortestPaths[cityName] > shortestPaths[minDistCity] + weight) {

				// Updating the shortest path of the city
				shortestPaths[cityName] = shortestPaths[minDistCity] + weight;
				//push the city in the array with its shortest path to check its adjacent later
				uncheckedVertices.push(make_pair(shortestPaths[cityName], cityName));
			}
		}


	}

	// Check if the final destination is unreachable
	if (shortestPaths[finalDistination] == INFINITE) {
		totalDistance = -1;
	}

	else {
		//store the final distination index in the list
		string current = finalDistination;
		path.push_back(current);

		// Backtrack from the destination to the source to get the shortest path
		while (current != startingNode) {

			list<pair <string, float>> adjacentVertices;
			myMap.getAdjacentList(current, adjacentVertices);
			list <pair <string, float>>::iterator listIterator;
			for (listIterator = adjacentVertices.begin(); listIterator != adjacentVertices.end(); listIterator++) {

				string adjVertex = listIterator->first;
				float weight = listIterator->second;
				if (shortestPaths[current] == shortestPaths[adjVertex] + weight) {
					current = adjVertex;
					path.push_back(current);
					break;
				}
			}

		}
		reverse(path.begin(), path.end());

		// Return the shortest path from the source to the destination
		totalDistance = shortestPaths[finalDistination];
	}
	return totalDistance;
}

