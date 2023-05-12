#include "graph.h"

#pragma once

// Adding Cities
void addCity(graph& myGraph);

// Adding Roads
void addOrEditRoad(graph& myGraph);
void addRoadFeedback(string city1, string city2, int message);