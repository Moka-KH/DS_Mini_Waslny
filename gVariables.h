#pragma once
#include <QStack>
#include<QHash>
#include <QPair>
#include "graph.h"

//to use in the program
inline QHash<QString, graph> maps;
inline graph* currentGraph=new graph();

//to use in path finder
inline QStack<QPair<QString, float>> path;
inline float totalDistance=-5;
inline QString startingVertex=" ";
inline QString targetVertex=" ";

//to use in addRoad
inline QString city1AddRoad =" ";
inline QString city2AddRoad =" ";
inline float distanceAddRoad =-5;

//to use in traverse
inline QString traverseVertex=" ";
