#pragma once
#include<fstream>
#include"graph.h"

void writeGraphToFile(graph& g, const string& filename);
void readGraphFromFile(graph& g, const string& filename);
unordered_map<string, graph> readMultipleGraphs(const string& directory);
void writeMultipleGraphs( unordered_map<string, graph>& graphs, const string& directory);
