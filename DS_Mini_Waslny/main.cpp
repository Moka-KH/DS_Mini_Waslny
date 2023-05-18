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
    /*graph myGraph;

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


    //gives a message that the road is deleted then the city is deleted
        // "messages are annoying =("
    myGraph.deleteCity("D");
    myGraph.display();

    //ask the user which road to delete between C and E 
        //"Doesn't make sense and needs to be removed," said the TA"
    myGraph.deleteCity("C");
    myGraph.display();

    myGraph.deleteCity("A");
    myGraph.display();
    */

    homePage(maps);
    return 0;
}
