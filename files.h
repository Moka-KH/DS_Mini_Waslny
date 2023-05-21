#ifndef FILES_H
#define FILES_H

#pragma once
#include <QFile>
#include <QTextStream>
#include <QMap>
#include "graph.h"

void writeGraphToFile(graph& g,const QString& filename);
void readGraphFromFile(graph& g,const QString& filename);
QHash<QString, graph> readMultipleGraphs(QString& directory);
void writeMultipleGraphs(const QHash<QString, graph>& graphs,const QString& directory);

#endif // FILES_H
