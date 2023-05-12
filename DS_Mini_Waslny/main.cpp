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

using namespace std;
unordered_map<string, graph> maps;

int main() {
    graph myGraph;
    
    // test case of dikstra
    myGraph.addCity("A");
    myGraph.addCity("B");
    myGraph.addCity("C");
    myGraph.addCity("D");
    myGraph.addCity("E");
    myGraph.addCity("F");
    myGraph.addCity("G");
    myGraph.addCity("H");
    myGraph.addCity("I");
    
    myGraph.addRoad("B", "A", 2);
    myGraph.addRoad("I", "A", 4);
    myGraph.addRoad("I", "C", 4);
    myGraph.addRoad("I", "G", 4);
    myGraph.addRoad("G", "I", 1);
    myGraph.addRoad("G", "F", 1);
    myGraph.addRoad("H", "G", 2);
    myGraph.addRoad("H", "E", 2);
    myGraph.addRoad("C", "F", 4);
    myGraph.addRoad("C", "E", 4);
    myGraph.addRoad("C", "D", 4);
    
    myGraph.display();
    BFS("A", myGraph);

    //Find(myGraph);

    /*float x;
    myGraph.addCity("Aaaa");
    myGraph.addCity("Bbbb");
    myGraph.addCity("Cccc");
    myGraph.addCity("Dddd");
    myGraph.addCity("Eeee");
    myGraph.addCity("Ffff");*/

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
    /*
    maps = readMultipleGraphs(".\\");

    homePage(maps);

    writeMultipleGraphs(maps, ".\\");
    */

    return 0;
}
