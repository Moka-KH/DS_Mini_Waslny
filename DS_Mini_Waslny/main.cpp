// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "consolUI.h"
#include "graph.h"
#include "algorithms.h"
#include <list>
#include <utility>
#include <unordered_map>
#include "GraphFileHandler.h"

using namespace std;
unordered_map<string, graph> maps;

int main() {
   maps=readMultipleGraphs(".\\");
    graph myGraph;
    vector<string> path;

    intro(maps);
    return 0;
}
