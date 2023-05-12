#pragma once
#include "graph.h"

void update(graph& myGraph);
void displayGraph(graph& myGraph);
void addGraph(unordered_map<string, graph>& maps);
void Find(graph& myMap);
void intro(unordered_map<string, graph>& maps);
void Traverse(graph& myGraph);
void workOnMap(unordered_map<string, graph>& maps);
int validateNumber();