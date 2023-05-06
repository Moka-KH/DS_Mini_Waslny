#pragma once
#include<fstream>
#include"graph.h"

void writeGraphToFile(graph& g, const string& filename);
void readGraphFromFile(graph& g, const string& filename);
