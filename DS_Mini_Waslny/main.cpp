// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "consolUI.h"
#include <list>
#include <utility>
#include <unordered_map>
using namespace std;

int main() {
    graph myGraph;
    
    /*myGraph.addCity("A");
    myGraph.addCity("B");
    myGraph.addCity("X");
    myGraph.addCity("F");
    myGraph.addCity("D");
    myGraph.addCity("K");*/


    // Roads
    /*myGraph.addRoad("A", "F", 15);
    myGraph.addRoad("F", "B", 20);
    myGraph.addRoad("F", "K", 10);
    myGraph.addRoad("F", "D", 60);
    myGraph.addRoad("B", "X", 25);
    myGraph.addRoad("D", "X", 10);

    myGraph.addRoad("F", "A", 15);
    my-Graph.addRoad("X", "B", 30);*/
    /*
    // Back Roads
    myGraph.addRoad("F", "A", 15);
    myGraph.addRoad("B", "F", 20);
    myGraph.addRoad("K", "F", 10);
    myGraph.addRoad("D", "F", 60);
    myGraph.addRoad("X", "B", 25);
    myGraph.addRoad("X", "D", 10);

    myGraph.display();

    myGraph.deleteCity("F");
    cout << "\nDeleted the City F\n";

    myGraph.display();
    */
    //myGraph.display();
    
    /*list<pair<string, float>> myList;
    myGraph.getOutAdjacent("F", myList);
    cout << "\tOut Adjacents: \n";
    for (auto& listPair : myList)
        cout << listPair.first << " (" << listPair.second << ")\n";

    myList.clear();
    myGraph.getInAdjacents("F", myList);
    cout << "\tIn Adjacents: \n";
    for (auto& listPair : myList)
        cout << listPair.first << " (" << listPair.second << ")\n";

    myList.clear();
    myGraph.getAdjacentVertices("F", myList);
    cout << "\tAll Adjacents: \n";
    for (auto& listPair : myList)
        cout << listPair.first << " (" << listPair.second << ")\n";*/

    /*myGraph.deleteCity("X");
    myGraph.display();*/
    intro();
    return 0;
}
