#ifndef FILES_H
#define FILES_H

#pragma once
#include <QFile>
#include <QTextStream>
#include <QMap>
#include "graph.h"

void writeGraphToFile(graph& g, const QString& filename);
void readGraphFromFile(graph& g, const QString& filename);
QMap<QString, graph> readMultipleGraphs(const QString& directory);
void writeMultipleGraphs(QMap<QString, graph>& graphs, const QString& directory);

#endif // FILES_H
