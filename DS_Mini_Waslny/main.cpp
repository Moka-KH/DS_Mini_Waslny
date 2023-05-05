// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"

using namespace std;

int main() {
    int choice;

    cout << "Welcome to the Mini Wasalni program!" << endl;

    do {
        cout << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Add graph (Cities and Distances between them)" << endl;
        cout << "2. Display graph data" << endl;
        cout << "3. Update graph data" << endl;
        cout << "4. Traverse the graph" << endl;
        cout << "5. Find shortest path between two cities" << endl;
        cout << "6. Exit program" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            // Add graph (Cities and Distances between them)
            // TODO: Implement function
            break;
        case 2:
            // Display graph data
            // TODO: Implement function
            break;
        case 3:
            // Update graph data
            // TODO: Implement function
            break;
        case 4:
            // Traverse the graph
            // TODO: Implement function
            break;
        case 5:
            // Find shortest path between two cities
            // TODO: Implement function
            break;
        case 6:
            // Exit program
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);

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