#include "graph.h"

#pragma once

// Adding Cities
void addCity(graph& myGraph);

// Adding Roads
void addOrEditRoad(graph& myGraph);
void addRoadFeedback(string city1, string city2, int message);

//Deleting Roads
void deleteRoad(graph& myGraph);
void deleteRoadFeedback(string city1, string city2, int message);

//Deleting Cities
void deleteCity(graph& myGraph);