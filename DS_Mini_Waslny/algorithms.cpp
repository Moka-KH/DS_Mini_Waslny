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
typedef pair<float, string> myPair;
const float INFINITE = FLT_MAX;

/**
* DFS - Traverses the graph and prints the vertices values
* @graph: the graph object to traverse
* @startVertex: the vertex to start applying the algorithm from
* 
* Return: nothing
*/
void DFS(graph& myGraph, string stratVetrex)
{
	// visited means it was printed on the screen
	unordered_map<string, bool> visited;

	// initialize the "visited" map to be all unvisited
	for (auto& x : myGraph.map)
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
			adjacencyList = myGraph.getAdjacents(currentNode);

			// iterate over the adjacent vertices of current node
			for (auto& it : adjacencyList)
				// push the non-visited adjacents into the stack
				if (!visited[it.first])
					NodesToCheckNeighbors.push(it.first);
		}
	}

	//traverse on isolated vertices
	for (auto& mapIterator : myGraph.map)
		if (visited[mapIterator.first] == false)
			cout << mapIterator.first << endl;

	cout << "End of Vertices" << endl;
}

void BFS(string startCity, graph& myGraph)
{
	// mark all vertices as not visited
	unordered_map<string, bool> visited;
	for (auto& x : myGraph.map)
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
		adjacencyList = myGraph.getAdjacents(currentCity);

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
	for (auto& mapIterator : myGraph.map)
	{
		if (visited[mapIterator.first] == false)
			cout << mapIterator.first << endl;
	}

	cout << "End of Vertices" << endl;
}

/**
 * Dijkstra's algorithm for finding the shortest path between two vertices in a graph
 * See this video before reading the function:
 * https://www.youtube.com/watch?v=pVfj6mxhdMw
 *
 * @param myMap A graphDS object representing the graph to search for the shortest path.
 * @param currentLocation The starting vertex for the shortest path search.
 * @param finalDistination The destination vertex for the shortest path search.
 * @param totalDistance The shortest distance between the two cities 
 *
 * @return The shortest path vector from the starting vertex to the destination vertex
 */
float Dijkstra(graph& myGraph, string startingNode, string targetVertex, vector<string>& path,vector <float>& distances )
{
	/*
	this structure is a priority queue using the minimum heap data structure(greater<myPair>)
	(a queue that puts the least element in its front)
	knowing a vertex means updating its adjacents' costs with new better values (if any)
	*/
	priority_queue<myPair, vector<myPair>, greater<myPair>> unKnownVertices;
	int citiesNum = myGraph.getVertexNum();

	// stores the shortest found path till now for all the verteces
	map<string,float> cost;

	// set all costs to infinity
	for (auto bucket = myGraph.map.begin(); bucket != myGraph.map.end();bucket++)
		cost.insert(make_pair(bucket->first, INFINITE));

	cost[startingNode] = 0;

	unKnownVertices.push(make_pair(0, startingNode));

	// Determine the shortest path for each city
	while (!unKnownVertices.empty())
	{
		// get the name of the city with minimum distance
		string currentVertexName = unKnownVertices.top().second;
		unKnownVertices.pop();

		list<pair <string, float>> outAdjacents = myGraph.getOutAdjacents(currentVertexName);

		// if taking a path using the current node to one of its adjacents is shorter
		// update it the costs with this value
		for (auto& adjacent: outAdjacents)
		{
			string adjacentName = adjacent.first;
			float weight = adjacent.second; // from the current vertex to this adjacent

			if (cost[adjacentName] > cost[currentVertexName] + weight)
			{
				cost[adjacentName] = cost[currentVertexName] + weight;
				// put this adjacent in the unknown vertices to know it later
				unKnownVertices.push(make_pair(cost[adjacentName], adjacentName)); // Why this push is here ?
			}
		}
	}

	// if there is no path to the target vertex
	if (cost[targetVertex] == INFINITE)
		return -1.0;
	else 
	{
		backTracking(myGraph, startingNode, targetVertex, path, distances, cost);
		return cost[targetVertex];
	}
}

void backTracking(graph& myGraph, string startingNode, string targetVertex, vector<string>& path, vector <float>& distances, map<string, float> cost)
{
	//store the final distination index in the list
	string current = targetVertex;
	path.push_back(current);

	// Backtrack from the destination to the source to get the shortest path
	while (current != startingNode)
	{
		list<pair <string, float>> adjacentVertices;
		adjacentVertices = myGraph.getInAdjacents(current);
		for (auto& listIterator : adjacentVertices) 
		{
			string adjVertex = listIterator.first;
			float weight = listIterator.second;
			if (cost[current] == cost[adjVertex] + weight)
			{
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
}
