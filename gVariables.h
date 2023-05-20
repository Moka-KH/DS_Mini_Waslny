#pragma once
#include <QStack>
#include <QPair>
#include "graph.h"

inline graph* currentGraph;
inline QStack<QPair<QString, float>> path;
inline float totalDistance;
