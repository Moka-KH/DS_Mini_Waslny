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
    
    // intro();

    graph g;

    g.addCity("cairo");
    g.addCity("alex");
    g.addCity("siwa");
    g.addCity("aswan");
    g.addCity("qena");

    g.display();


    g.addRoad("cairo", "alex", 88);
    g.addRoad("alex", "cairo", 90);
    g.addRoad("aswan", "cairo", 200);
    g.addRoad("aswan", "siwa", 300);
    g.addRoad("siwa", "aswan", 300);

    g.display();



    g.deleteRoad("aswan", "siwa");
    g.deleteRoad("siwa", "aswan");

    g.display();


    g.deleteCity("cairo");

    g.display();




    g.display();




    return 0;
}
