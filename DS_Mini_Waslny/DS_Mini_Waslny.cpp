// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include "graphDS.h"
#include <unordered_map>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    graphDS mygraph;

    mygraph.addCity("Alex");
    mygraph.addCity("Mahalla");
    mygraph.addCity("Cairo", "Alex", 200);

    cout << "Done adding!!\n";

    mygraph.display();

   //cout << "Done displaying!!\n";

   // mygraph.deleteCity("Alex");

   // mygraph.deleteCity("Asswan");
   // 
   //cout << "Done deleteing the city!!\n";

    //mygraph.deleteRoad("Cairo", "Alex");

    //mygraph.display();









}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
