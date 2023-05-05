#pragma once
#include "graph.h"

void DFS(graph&, string);
void BFS(string startCity, graph graph);
float Dijkstra(graph&, string, string, vector<string>&);