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

    mygraph.addCity("cairo", "alexandria", 200);
    mygraph.addCity("cairo", "Monfia", 150);
    mygraph.addCity("cairo", "Giza", 50);

    mygraph.addCity("alexandria", "North cost", 180);
    mygraph.addCity("alexandria", "Obour", 300);

    mygraph.addCity("Obour", "Kafr ELshiekh", 250);

    mygraph.addCity("Assuit", "Quena", 350);
    mygraph.addCity("Aswan", "monofia", 380);


    mygraph.addCity("Aswan", "test", 111);

    mygraph.addCity("empty", "xxx", 000);






    cout << "Done adding!!\n";

    mygraph.display();

    cout << "Done displaying!!\n";
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
