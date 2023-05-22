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
#include <queue>
#include <stack>
#include "coloredOutput.cpp"
#include"graph.h"
#include "enumerators.cpp"

using namespace std;
typedef pair<float, string> myPair;
const float infinity = FLT_MAX;

/**
* DFS - Traverses the graph and prints the vertices values
* @graph: the graph object to traverse
* @startVertex: the vertex to start applying the algorithm from
* 
* Return: nothing
*/
void DFS(graph& myGraph, string startVetrex)
{
	if (!myGraph.vertexExists(startVetrex))
	{
		failureMessage(startVetrex + " doesn't exist =|\n");
		return;
	}
	unordered_map<string, bool> visited;

	// initialize all vertices to be "unvisited" first
	for (auto& x : myGraph.map)
		visited[x.first] = false;

	stack<string> NodesToCheckNeighbors;
	NodesToCheckNeighbors.push(startVetrex);

	queue<string> DFSQueue;

	//traverse on connected vertices 
	while (!NodesToCheckNeighbors.empty())
	{
		// return top vertex and pop it to mark it as "visited"
		string currentNode = NodesToCheckNeighbors.top();
		NodesToCheckNeighbors.pop();

		if (!visited[currentNode])
		{
			// print & mark the current vertex as "visited"
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
}

/**
* BFS - Traverses the graph and prints the vertices values
* @graph: the graph object to traverse
* @startCity: the vertex to start applying the algorithm from
*
* Return: nothing
*/
void BFS(string startCity, graph& myGraph)
{
	if (!myGraph.vertexExists(startCity))
	{
		failureMessage(startCity + " doesn't exist =|\n");
		return;
	}
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

	successMessage("End of Vertices\n");
}

/**
 * Dijkstra's algorithm for finding the shortest path between two vertices in a graph
 * See this video before reading the function:
 * https://www.youtube.com/watch?v=pVfj6mxhdMw
 *
 * @param myMap A graphDS object representing the graph to search for the shortest path.
 * @param currentLocation The starting vertex for the shortest path search.
 * @param finalDistination The destination vertex for the shortest path search.
 * @param path, that includes the cities from the starting city to the end city and distances between them.
 *
 * @return The shortest distanse from the starting vertex to the destination vertex
 */
float Dijkstra(graph& myGraph, string startingNode, string targetVertex, stack<pair<string, float>>& path)
{
	/*
	this structure is a priority queue using the minimum heap data structure(greater<myPair>)
	(a queue that puts the least element in its front)
	knowing a vertex means updating its adjacents' costs with new better values (if any)
	*/
	priority_queue<myPair, vector<myPair>, greater<myPair>> unKnownVertices;

	// stores the shortest found path till now for all the verteces & set all costs to infinity
	map<string,float> cost;
	for (auto bucket = myGraph.map.begin(); bucket != myGraph.map.end(); bucket++)
		cost.insert(make_pair(bucket->first, infinity));

	cost[startingNode] = 0;

	// stores the previous vertex of each vertex (set it all to "" )
	unordered_map<string, string> previousVerteces;
	for (auto bucket = myGraph.map.begin(); bucket != myGraph.map.end(); bucket++)
		previousVerteces[bucket->first] = "";

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
				// update the cost
				cost[adjacentName] = cost[currentVertexName] + weight;
				
				// set the preceding vertex
				previousVerteces[adjacentName] = currentVertexName;

				// put this adjacent in the unknown vertices to know it later
				unKnownVertices.push(make_pair(cost[adjacentName], adjacentName));
			}
		}
	}

	// if there is no path to the target vertex
	if (cost[targetVertex] == infinity)
		return -1.0;
	else 
	{
		path = backTracking(myGraph, startingNode, targetVertex, previousVerteces);
		return cost[targetVertex];
	}
}

/**
* This function does the backtracking for Dijkstra's algorithm to return the path in detail
* 
* @param myGraph the graph that Dijkstra's was implemented on
* @param startingVertex the vertex the Dijkstra's started from
* @param targetVertex the target destination
* @param previousVerteces hash table of every city and its previous vertex
* 
* @return a list of pairs containing the name of each city and the distance to reach it from its previous vertex
*/
stack<pair<string, float>> backTracking(graph& myGraph, string startingVertex, string targetVertex, unordered_map<string, string> previousVerteces)
{
	stack<pair<string, float>> path;
	string currentVertex = targetVertex;
	string previousVertex = previousVerteces[currentVertex];
	float distance;

	while (currentVertex != startingVertex)
	{
		// get the distance from previous vertex to the current one
		list<pair<string, float>> inCurrentAdjacent = myGraph.getInAdjacents(currentVertex);
		for (auto listPair : inCurrentAdjacent)
			if (listPair.first == previousVertex)
				distance = listPair.second;

		path.push(make_pair(currentVertex, distance));

		currentVertex = previousVertex;
		previousVertex = previousVerteces[currentVertex];
	}
	return path;
}
