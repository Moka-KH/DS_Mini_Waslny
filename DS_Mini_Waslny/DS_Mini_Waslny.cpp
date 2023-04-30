// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graphDS.h"
#include "Wasalny.h"
#include "DFS.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";

    graphDS mygraph;

    mygraph.addCity("Cairo");
    mygraph.addCity("Alex");
    mygraph.addCity("Aswan", "Cairo", 400);
    mygraph.addCity("Mahalla", "Aswan", 200);
    cout << "Done adding!!\n";

    // Wasalny uber;
    DFS(mygraph, "Aswan");
}