#include <stack>
#include "graph.h"

#pragma once

void updateMap(graph& myGraph);
void Traverse(graph& mygraph);
void pathFinder(graph& myMap);
void displayPath(stack<pair<string, float>> path, string startingCity);