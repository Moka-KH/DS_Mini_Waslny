#pragma once
#include <QStack>
#include <QPair>
#include "graph.h"

inline graph* currentGraph=new graph();
inline QStack<QPair<QString, float>> path;
inline float totalDistance=-5;
inline QString startingVertex=" ";
inline QString targetVertex=" ";
