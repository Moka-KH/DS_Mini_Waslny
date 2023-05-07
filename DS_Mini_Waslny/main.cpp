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
    myGraph.addCity("A");
    myGraph.addCity("B");
    myGraph.addCity("C");
    myGraph.addCity("D");
    myGraph.addCity("E");
    myGraph.addCity("F");
    myGraph.addCity("G");
    myGraph.addCity("H");
    myGraph.addCity("I");

    myGraph.addRoad("A", "B", 3);
    myGraph.addRoad("A", "I", 3);
    myGraph.addRoad("I", "C", 3);
    myGraph.addRoad("I", "G", 3);
    myGraph.addRoad("C", "D", 3);
    myGraph.addRoad("C", "E", 3);
    myGraph.addRoad("C", "F", 3);
    myGraph.addRoad("G", "F", 3);
    myGraph.addRoad("G", "H", 3);
    myGraph.addRoad("E", "H", 3);


    // Back Roads
    myGraph.addRoad("B", "A", 3);
    myGraph.addRoad("I", "A", 3);
    myGraph.addRoad("C", "I", 3);
    myGraph.addRoad("G", "I", 3);
    myGraph.addRoad("D", "C", 3);
    myGraph.addRoad("E", "C", 3);
    myGraph.addRoad("F", "C", 3);
    myGraph.addRoad("F", "G", 3);
    myGraph.addRoad("H", "G", 3);
    myGraph.addRoad("H", "E", 3);

    myGraph.display();

    cout << "===============================================================" << endl;
    /*
    list<pair<string, float>> adjacencyList;
    graph.getOutAdjacent("A", adjacencyList);

    cout << "Adjacents of A" << endl;
    for (auto& it : adjacencyList)
    {
        cout << it.first << endl;
    }
    */
    DFS(myGraph, "A");

    /*graph myGraph;
    myGraph.addCity("Cairo");
    myGraph.addCity("Alex");
    myGraph.addRoad("Cairo", "Alex", 88);
    myGraph.addRoad("Alex", "Cairo", 90);*/

 /*   list<pair <string, float>> list;
    myGraph.getAdjacentList("Alex", list);
    for (auto& x : list)
        cout << x.first << ' ' << x.second << endl;

    myGraph.addRoad("Cairo", "Alex", 11);
    myGraph.getAdjacentList("Cairo", list);
    for (auto& x : list)
        cout << x.first << ' ' << x.second << endl;*/

    //intro();

   /* myGraph.addCity("Aswan");
    myGraph.addCity("siwa");
    myGraph.addCity("suez");
    myGraph.addRoad("Aswan", "siwa", 100);
    myGraph.addRoad("Aswan", "Cairo", 200); 
    myGraph.addRoad("siwa", "Aswan", 100);
    Traverse(myGraph);*/

    return 0;
}
