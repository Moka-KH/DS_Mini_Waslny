#include <stack>
#include <queue>
#include "graph.h"

#pragma once

void DFS(graph& myGraph, string startVetrex);
void BFS(string startCity, graph& myGraph);
float Dijkstra(graph& myGraph, string startingNode, string targetVertex, stack<pair<string, float>>& path);

stack<pair<string, float>> backTracking(graph& myGraph, string startingVertex, string targetVertex, unordered_map<string, string> previousVerteces);