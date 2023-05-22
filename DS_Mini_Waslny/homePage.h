#pragma once
#include "graph.h"

void addMap(unordered_map<string, graph>& maps);
void homePage(unordered_map<string, graph>& maps);
void mapsDashboard(unordered_map<string, graph>& maps);
string chooseMapDashboard(unordered_map<string, graph>& maps);
float validateFloat();