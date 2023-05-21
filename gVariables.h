#pragma once
#include <QStack>
#include<QHash>
#include <QPair>
#include "graph.h"

inline QHash<QString, graph> maps;
inline graph* currentGraph=new graph();
inline QStack<QPair<QString, float>> path;
inline float totalDistance=-5;
inline QString startingVertex=" ";
inline QString targetVertex=" ";
