#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "graph.h"
#include<QStack>
#include<QPair>
#include<QHash>

QQueue<QString> DFS(graph& myGraph, QString startVetrex);

float Dijkstra(graph& myGraph,QString startingNode, QString targetVertex, QStack<QPair<QString, float>>& path);

QStack<QPair<QString, float>> backTracking(graph& myGraph, QString startingVertex, QString targetVertex, QHash<QString, QString> previousVerteces);


#endif // ALGORITHMS_H
