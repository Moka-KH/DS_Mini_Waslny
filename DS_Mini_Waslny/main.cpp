// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "consolUI.h"
#include <list>
using namespace std;

int main() {
    
    graph myGraph;
    myGraph.addCity("Cairo");
    myGraph.addCity("Alex");
    myGraph.addRoad("Cairo", "Alex", 88);
    myGraph.addRoad("Alex", "Cairo", 90);

    /*list<pair <string, float>> list;
    myGraph.getAdjacentList("Alex", list);
    for (auto& x : list)
        cout << x.first << ' ' << x.second << endl;

    myGraph.addRoad("Cairo", "Alex", 11);
    myGraph.getAdjacentList("Cairo", list);
    for (auto& x : list)
        cout << x.first << ' ' << x.second << endl;*/

    // intro();

    myGraph.addCity("Aswan");
    myGraph.addCity("siwa");
    myGraph.addCity("suez");
    myGraph.addRoad("Aswan", "siwa", 100);
    myGraph.addRoad("Aswan", "Cairo", 200); 
    myGraph.addRoad("siwa", "Aswan", 100);
    Traverse(myGraph);

    return 0;
}
