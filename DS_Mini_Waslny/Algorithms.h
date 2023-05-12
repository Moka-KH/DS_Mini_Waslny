#pragma once
#include "graph.h"

void DFS(graph& myGraph, string stratVetrex);
void BFS(string startCity, graph& myGraph);
float Dijkstra(graph&, string, string, vector<string>&,vector<float>&);