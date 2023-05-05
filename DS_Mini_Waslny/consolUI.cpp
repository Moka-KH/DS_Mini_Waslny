#pragma once
#include<iostream>
#include "graph.h"
#include "algorithms.h"
#include "consolUI.h"

using namespace std;

/**
 * @brief This function allows the user to update the graph data structure by adding new cities,
 *        adding new edges between existing cities, deleting existing cities, or deleting edges between existing cities.
 *
 * @param myGraph a reference to the graph data structure that the user wants to update.
 * @retun void
 */
void update(graph& myGraph)
{
    int choice;
    cout << "Enter An Option (1-5):\n";
    cout << "1. Add New City\n";
    cout << "2. Add New Road\n";
    cout << "3. Delete City\n";
    cout << "4. Delete Road\n";
    cout << "5. Return to the Main menu\n";
    cin >> choice;

    switch (choice) {
    case 1:
    {
        string AddedCity;
        cout << "Enter the name of the new city that you want to add it: \n";
        cin >> AddedCity;

        if (myGraph.addCity(AddedCity))
            update(myGraph);

        break;
    }
    case 2:
    {
        int choice;
        string city1, city2;
        float distance;
        cout << "Enter the name of the two cities\n name of city number 1 is:\n";
        cin >> city1;
        cout << "name of city number 2 is:\n";
        cin >> city2;
        cout << "Enter the distance between them \n";
        cin >> distance;


        /*
      1- the user will add a directed road or an undirected road
      2- if dircted call addRoad once
      3-if undirected call addRoad twice and switch the cities names
      */
        cout << "Is the road will be one way or roundway ?\n"
            << "Press: 1 if it is one way \t press: 2 if it is roundway \n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "If the road goes from " << city1 << " to " << city2 << " press 1\n"
                << "If the road goes from " << city2 << " to " << city1 << " press 2\n";
            cin >> choice;
            if (choice == 1) {
                if (myGraph.addRoad(city1, city2, distance))
                    update(myGraph);
            }
            else {
                if (myGraph.addRoad(city2, city1, distance))
                    update(myGraph);
            }
        }
        if (choice == 2)
        {
            if (myGraph.addRoad(city1, city2, distance))
                update(myGraph);
            if (myGraph.addRoad(city2, city1, distance))
                update(myGraph);

        }

        break;
    }
    case 3:
    {
        string DeletedCity;
        cout << "Enter the name of the new city that you want to delete it: \n";
        cin >> DeletedCity;

        if (myGraph.deleteCity(DeletedCity))
            update(myGraph);

        break;
    }
    case 4:
    {
        string city1, city2;
        cout << "Enter the name of the two cities\n name of city number 1 is:\n";
        cin >> city1;
        cout << "name of city number 2 is:\n";
        cin >> city2;

        if (myGraph.deleteRoad(city1,city2))
        {
            update(myGraph);
        }       
        break;
    }
    case 5:
        return;
    default:
    {
        cout << "invalid choice :\\n";
        update(myGraph);
    }
    }

}

/**
* @brief This function displays the adjacency list representation of the given graph.
*
* @param myGraph A reference to the graph object.
* @return void.
*/
void displayGraph(graph& myGraph)
{
    myGraph.display();
}

/**
* @brief This function creates a new graph object and prompts the user to
*        update it by adding cities and roads.
*
* @return graph The newly created and updated graph object.
*/
graph addGraph()
{
    graph newGraph;
    char choice;
    cout << "Your Graph is created sucsessfully," << endl
        << "if you want to update it by adding cities and roads to it entre 'y', " << endl
        << "Else if you want to return to the main menu entre 'n' " << endl;
    cin >> choice;
    if (choice == 'y')
        update(newGraph);
    else if (choice == 'n')
        return newGraph;
    else {
        cout << "Invalid input, you will be returned to the main menu to complete your journey!";
        return newGraph;
    }
}

/**
* @brief This function finds the shortest path between two cities in a graph
*        using Dijkstra's algorithm.
*
* @param myMap A reference to the graph object containing cities and roads.
* @return void.
*/
void Find(graph& myMap)
{
    string city1, city2;
    float theShortestDistance;
    cout << "Let's start our journey in finding the shortest path!" << endl
        << "Please enter the starting city of your path to start your journey with us," << endl
        << "Your starting city is:";
    cin >> city1;
    cout << "Now, Please enter Your destination city," << endl
        << "Your destination city is:";
    cin >> city2;
    vector<string> shortestPathVector;
    theShortestDistance = Dijkstra(myMap, city1, city2, shortestPathVector);
    if (theShortestDistance == -1)
    {
        cout << "=============================================================" << endl
            << "There is no path between  " << city1 << " and " << city2 << endl;
    }
    else
    {
        cout << "=============================================================" << endl
            << "The total distance of the shortest path between " << city1 << " and " << city2 << "is = " << theShortestDistance;


        vector<string>::iterator vectorIt = shortestPathVector.begin();

        while (vectorIt != shortestPathVector.end())
        {
            cout << *vectorIt << " -> ";
            vectorIt++;
        }
        cout << endl;
    }
}

/**
* intro - greeting the user (first thing the user sees)
*
* Retrun: nothing
*/
void intro()
{
    graph myGraph;

    cout << "\t\t\t\t\tWelcome to the Mini Wasalni program!" << endl;
    cout << "\t\t\t===================================================================" << endl;
    cout << "\t\t\t===================================================================" << endl;
    do {
        int mainChoice;
        cout << endl << endl << endl;
        cout << "Please choose from the following options:" << endl;
        cout << "1. Add new map" << endl;
        cout << "2. Work on an existing map" << endl;
        cout << "3. Exit program" << endl;

        cin >> mainChoice;

        if (mainChoice == 1) {
            myGraph = addGraph();
        }
        else if (mainChoice == 2)
        {
            do {
                int choice;
                cout << endl << endl << endl;
                cout << "Please choose from the following options:" << endl;
                cout << "1. Add graph (Cities and Distances between them)" << endl;
                cout << "2. Display graph data" << endl;
                cout << "3. Update graph data" << endl;
                cout << "4. Traverse the graph" << endl;
                cout << "5. Find shortest path between two cities" << endl;
                cout << "6. Return to the main menu" << endl;
                cout << "===================================================================" << endl;

                cin >> choice;

                if (choice == 1)
                {
                    myGraph = addGraph();
                }
                else if (choice == 2)
                {
                    displayGraph(myGraph);
                }
                else if (choice == 3)
                {
                    update(myGraph);
                }
                else if (choice == 4)
                {
                    string startCity;
                    cout << "Enter the start city name:\n";
                    cin >> startCity;
                    int traverseChoice;
                    cout << "press 0 if you want to traverse using DFS\n"
                         << "press 1 if you want to traverse using BFS\n";
                    cin >> traverseChoice;
                    
                    if (BreadthFS == traverseChoice)
                        Traverse(BreadthFS, myGraph, startCity);
                    else if (DepthFS == traverseChoice)
                        Traverse(DepthFS, myGraph, startCity);
                    else
                        cout << "Invalid Choice please try again :(\n";

                }
                else if (choice == 5)
                {
                    Find(myGraph);
                }
                else if (choice == 6)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (true);
        }
        else if (mainChoice == 3)
        {
            cout << "Goodbye!" << endl;
            // exit function goes here
        }
        else
            cout << "Invalid choice ,Please try again \n";

        

    } while (true);
}


void Traverse(traverse parameter, graph& mygraph, string startCity)
{
    if (parameter == DepthFS)
    {
        DFS(mygraph,startCity);
    }
    else
    {
        BFS(startCity, mygraph);
    }
}

