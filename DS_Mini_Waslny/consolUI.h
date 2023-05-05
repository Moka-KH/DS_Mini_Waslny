#pragma once
#include "graph.h"

enum traverse
{
    DepthFS = 0, BreadthFS = 1
};

void update(graph& myGraph);
void displayGraph(graph& myGraph);
graph addGraph();
void Find(graph& myMap);
void intro();
void Traverse(traverse parameter);