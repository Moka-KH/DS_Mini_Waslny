#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <stack>
#include "graph.h"
#include "algorithms.h"
#include <float.h>
#include <string.h>
#include <list>
#include<queue>

using namespace std;
typedef pair<float, string> iPair;
const float INFINITE = FLT_MAX;

/**
* DFS - Traverses the graph and prints the vertices values
* @graph: the graph object to traverse
* @startVertex: the vertex to start applying the algorithm from
* 
* Return: nothing
*/
void DFS(graph& graph, string stratVetrex)
{
	// visited means it was printed on the screen
	unordered_map<string, bool> visited;

	// initialize the "visited" map to be all unvisited
	for (auto& x : graph.map)
		visited[x.first] = false;

	stack<string> NodesToCheckNeighbors;
	NodesToCheckNeighbors.push(stratVetrex);

	//traverse on connected vertices 
	while (!NodesToCheckNeighbors.empty())
	{
		// take the top of the stack in a variable and pop it
		string currentNode = NodesToCheckNeighbors.top();
		NodesToCheckNeighbors.pop();

		// print & get the non-visited adjacents of the non-visited
		if (!visited[currentNode])
		{
			cout << currentNode << endl;
			visited[currentNode] = true;

			// get the adjacency list of the current vertex
			list<pair<string, float>> adjacencyList;
			graph.getAdjacentVertices(currentNode, adjacencyList);

			// iterate over the adjacent vertices of current node
			for (auto& it : adjacencyList)
				// push the non-visited adjacents into the stack
				if (!visited[it.first])
					NodesToCheckNeighbors.push(it.first);
		}
	}

	//traverse on isolated vertices
	for (auto& mapIterator : graph.map)
		if (visited[mapIterator.first] == false)
			cout << mapIterator.first << endl;

	cout << "End of Vertices" << endl;
}

// ================================================================================
void BFS(string startCity, graph graph)
{
	// mark all vertices as not visited
	unordered_map<string, bool> visited;
	for (auto& x : graph.map)
		visited[x.first] = false;

	// create a queue for BFS
	queue<string> queue;

	// mark the current node as visited and enqueue it
	visited[startCity] = true;
	queue.push(startCity);

	string currentCity;

	while (!queue.empty())
	{
		// dequeue a vertex from queue and print it
		currentCity = queue.front();
		cout << currentCity << endl;

		// get the adjacency list of the current vertex
		list<pair<string, float>> adjacencyList;
		graph.getAdjacentVertices(currentCity, adjacencyList);

		// get all adjacent vertices of the dequeued vertex
		// if an adjacent vertex has not been visited, mark it visited and enqueue it
		for (auto& it : adjacencyList)
		{
			if (!visited[it.first])
			{
				visited[it.first] = true;
				queue.push(it.first);
			}
		}
		// dequeue the visited vertex from the queue
		queue.pop();
	}

	//traverse on isolated vertices
	for (auto& mapIterator : graph.map)
	{
		if (visited[mapIterator.first] == false)
			cout << mapIterator.first << endl;
	}

	cout << "End of Vertices" << endl;
}


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
float Dijkstra(graph& myMap, string startingNode, string finalDistination, vector<string>& path,vector <float>& distances ) {

	/*
	greater<ipair> makes the queue uses the minimum heap data structure(binary tree)
	which puts the smallest element at the top of the queue
	*/
	priority_queue<iPair, vector<iPair>, greater<iPair> > uncheckedVertices;

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
		myMap.getOutAdjacent(minDistCity, adjacentVertices);

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
		return -1.0;
	}

	else {
		//store the final distination index in the list
		string current = finalDistination;
		path.push_back(current);

		// Backtrack from the destination to the source to get the shortest path
		while (current != startingNode) {

			list<pair <string, float>> adjacentVertices;
			myMap.getAdjacentVertices(current, adjacentVertices);
			list <pair <string, float>>::iterator listIterator;
			for (listIterator = adjacentVertices.begin(); listIterator != adjacentVertices.end(); listIterator++) {

				string adjVertex = listIterator->first;
				float weight = listIterator->second;
				if (shortestPaths[current] == shortestPaths[adjVertex] + weight) {
					current = adjVertex;
					path.push_back(current);
					distances.push_back(weight);
					break;
				}
			}

		}
		//cities name
		reverse(path.begin(), path.end());
		//distances between cities displayed
		reverse(distances.begin(), distances.end());

		// Return the shortest path from the source to the destination
		
		return shortestPaths[finalDistination];
	}

}
