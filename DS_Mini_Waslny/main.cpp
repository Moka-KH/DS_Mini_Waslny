// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "consolUI.h"

using namespace std;

int main() {
    int choice;
    graph myGraph;

    cout << "\t\t\t\t\tWelcome to the Mini Wasalni program!" << endl;
    cout << "\t\t\t===================================================================" << endl;
    cout << "\t\t\t===================================================================" << endl;

    do {
        cout << endl << endl << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Add graph (Cities and Distances between them)" << endl;
        cout << "2. Display graph data" << endl;
        cout << "3. Update graph data" << endl;
        cout << "4. Traverse the graph" << endl;
        cout << "5. Find shortest path between two cities" << endl;
        cout << "6. Exit program" << endl;
        cout << "===================================================================" << endl;

        cin >> choice;

        if (choice == 1) {
            myGraph = addGraph();
        }
        else if (choice == 2) {
            displayGraph(myGraph);
        }
        else if (choice == 3) {
            update(myGraph);
        }
        else if (choice == 4) {
            // traverse goes here 
        }
        else if (choice == 5) {
            Find(myGraph);
        }
        else if (choice == 6) {
            cout << "Goodbye!" << endl;
            // exit function goes here
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
            return 0;
        }
           
    } while (true);

    return 0;
}




//int main()
//{
//    cout << "Hello World!\n";
//
//    graph mygraph;
//
//    mygraph.addCity("Cairo");
//    mygraph.addCity("Alex");
//    mygraph.addCity("Aswan", "Cairo", 400);
//    mygraph.addCity("Mahalla", "Aswan", 200);
//    cout << "Done adding!!\n";
//
//    DFS(mygraph, "Aswan");
//}