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
    vector<string> path;
    float x;
    myGraph.addCity("Aaaa");
    myGraph.addCity("Bbbb");
    myGraph.addCity("Cccc");
    myGraph.addCity("Dddd");
    myGraph.addCity("Eeee");
    myGraph.addCity("Ffff");


    myGraph.addRoad("Aaaa", "Bbbb", 2);
    myGraph.addRoad("Aaaa", "Cccc", 4);
    myGraph.addRoad("Bbbb", "Cccc", 1);
    myGraph.addRoad("Bbbb", "Eeee", 2);
    myGraph.addRoad("Bbbb", "Dddd", 4);
    myGraph.addRoad("Cccc", "Eeee", 3);
    myGraph.addRoad("Eeee", "Dddd", 3);
    myGraph.addRoad("Eeee", "Ffff", 2);
    myGraph.addRoad("Dddd", "Ffff", 3);

    
    
    Find(myGraph);

    //graph myGraph;
    //myGraph.addCity("A");
    //myGraph.addCity("B");
    //myGraph.addCity("C");
    //myGraph.addCity("D");
    //myGraph.addCity("E");
    //myGraph.addCity("F");
    //myGraph.addCity("G");
    //myGraph.addCity("H");
    //myGraph.addCity("I");

    //myGraph.addRoad("A", "B", 3);
    //myGraph.addRoad("A", "I", 3);
    //myGraph.addRoad("I", "C", 3);
    //myGraph.addRoad("I", "G", 3);
    //myGraph.addRoad("C", "D", 3);
    //myGraph.addRoad("C", "E", 3);
    //myGraph.addRoad("C", "F", 3);
    //myGraph.addRoad("G", "F", 3);
    //myGraph.addRoad("G", "H", 3);
    //myGraph.addRoad("E", "H", 3);


    ////// Back Roads
    //myGraph.addRoad("B", "A", 3);
    //myGraph.addRoad("I", "A", 3);
    //myGraph.addRoad("C", "I", 3);
    //myGraph.addRoad("G", "I", 3);
    //myGraph.addRoad("D", "C", 3);
    //myGraph.addRoad("E", "C", 3);
    //myGraph.addRoad("F", "C", 3);
    //myGraph.addRoad("F", "G", 3);
    //myGraph.addRoad("H", "G", 3);
    //myGraph.addRoad("H", "E", 3);


    //list<pair <string, float>> adjList;
    //list <pair <string, float>>::iterator listIterator;


    //myGraph.getAdjacentVertices("A", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;
    //cout << endl;

    //myGraph.getAdjacentVertices("B", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;
    //cout << endl;

    //myGraph.getAdjacentVertices("C", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;
    //cout << endl;

    //myGraph.getAdjacentVertices("D", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;
    //cout << endl;

    //myGraph.getAdjacentVertices("E", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl; myGraph.getAdjacentVertices("A", adjList);
    //cout << endl;

    //myGraph.getAdjacentVertices("F", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl; myGraph.getAdjacentVertices("A", adjList);
    //cout << endl;

    //myGraph.getAdjacentVertices("G", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;
    //cout << endl;

    //myGraph.getAdjacentVertices("H", adjList);
    //for (listIterator = adjList.begin(); listIterator != adjList.end(); listIterator++)
    //    cout << listIterator->first << "\t\t" << listIterator->second << endl;





    /*graph myGraph;
    myGraph.addCity("Cairo");
    myGraph.addCity("Alex");
    myGraph.addRoad("Cairo", "Alex", 88);
    myGraph.addRoad("Alex", "Cairo", 90);*/


    //intro();


    return 0;
}
