// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graph.h"
#include "algorithms.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";

    graph mygraph;

    mygraph.addCity("Cairo");
    mygraph.addCity("Alex");
    mygraph.addCity("Aswan", "Cairo", 400);
    mygraph.addCity("Mahalla", "Aswan", 200);
    cout << "Done adding!!\n";

    DFS(mygraph, "Aswan");
}