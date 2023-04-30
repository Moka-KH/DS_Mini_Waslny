#include <unordered_map>
#include <vector>
#include <utility>
#include <string.h>
#include <stack>
#include "graphDS.h"

void DFS(graphDS graph, string startvertex)
{
	string start = startvertex;
	unordered_map<string, bool> visited;

	// initialize the "visited" map to be all unvisited
	for (auto& x : graph.map)
		visited[x.first] = false;

	stack<string> S;

	visited[start] = true;
	S.push(start);

	bool firstStackEntry = true;

	while (!S.empty())
	{
		string temp = S.top();

		// the action to do on the vertex (here we print)
		cout << (!firstStackEntry ? temp + ' ' : "");
		firstStackEntry = false;
		S.pop();

		// get the adjacency list of the current vertex
		list<pair<string, int>> adjacencyList;
		graph.getAdj(temp, adjacencyList);

		// iterate over the adjacent vertices of temp
		for (auto& it : adjacencyList)
		{
			// if you find a node that is not visited
			if (!visited[it.first])
			{
				// push it to the stack
				S.push(it.first);
				// and mark it as visited
				visited[it.first] = true;
			}
		}
	}
	cout << startvertex << ' ' << endl;

	// if you wish, print the isolated vertices
}