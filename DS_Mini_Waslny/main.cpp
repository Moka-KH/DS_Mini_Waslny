// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "homePage.h"
#include <list>
#include <utility>
#include <unordered_map>
#include "files.h"
#include "dashboard.h"

using namespace std;
unordered_map<string, graph> maps;

int main() {
    graph myGraph;

    myGraph.addCity("A");
    myGraph.addCity("B");
    myGraph.addCity("C");
    myGraph.addCity("D");
    myGraph.addCity("E");

    myGraph.addRoad("B", "A", 4);
    myGraph.addRoad("B", "C", 1);
    myGraph.addRoad("C", "A", 10.55);

    myGraph.addRoad("C", "E", 3);
    myGraph.addRoad("E", "C", 4);

    myGraph.addRoad("C", "D", 4);
    myGraph.addRoad("D", "C", 4);

    myGraph.addRoad("A", "A", 0.5);

    myGraph.deleteRoad("A", "B");
    myGraph.display();

    return 0;
}
