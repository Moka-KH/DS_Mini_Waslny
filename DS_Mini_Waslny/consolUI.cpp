#pragma once
#include<iostream>
#include <unordered_map>
#include "graph.h"
#include "algorithms.h"
#include "consolUI.h"
#include "GraphFileHandler.h"
#include <string>

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
    do
    {
        cout << "\t\t\t\t\tUpdating " << myGraph.name << endl;
        cout << "1. Add New City\n";
        cout << "2. Add / Edit a Road\n";
        cout << "3. Delete City\n";
        cout << "4. Delete Road\n";
        cout << "5. Return to the Working on " << myGraph.name << "\n";
        cin >> choice;

        if (choice == 1)
        {
            string AddedCity;
            cout << "\tName: ";
            cin >> AddedCity;

            if (myGraph.addCity(AddedCity))
                update(myGraph);
        }
        else if (choice == 2)
        {
            string city1, city2;
            float distance;
            cout << "Adding / Updating Road:\n"
                << "\tCity 1: ";
            cin >> city1;
            cout << "\tCity 2: ";
            cin >> city2;
            cout << "\tDistance: ";
            // Handling exception 
            do {
                try {
                    cin >> distance;
                    //if we have string instead of numerical number
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw std::runtime_error("Invalid input=(  Please enter a numerical input");
                    }
                    //ensure that the distance is positive
                    else if (distance <= 0) 
                        cout << "please enter a psitive distance"<<endl;
                    else
                        break;
                }
                catch (runtime_error& exp)
                {
                    cout << exp.what() << endl;
                }
                
            } while (true);

            /*
             1- the user will add a directed road or an undirected road
             2- if dircted call addRoad once
             3-if undirected call addRoad twice and switch the cities names
            */
            cout << "One way or roundway Road ?\n"
                << "1- One way \t 2- Roundway \n";
            int choice;
            cin >> choice;
            if (choice == 1) // one way
            {
                cout << "1- from " << city1 << " to " << city2 << "\n"
                    << "2- from " << city2 << " to " << city1 << "\n";
                cin >> choice;
                // we call the addRoad() in a condition to catch errors
                // don't remove the braces here.. a problem with nested if else will happen
                if (choice == 1)
                {
                    if (myGraph.addRoad(city1, city2, distance))
                        update(myGraph);
                }
                else if (choice == 2)
                {
                    if (myGraph.addRoad(city2, city1, distance))
                        update(myGraph);
                }
                else
                {
                    cout << "invalid choice :/\n";
                }
            }
            else if (choice == 2) // roundway
            {
                if (myGraph.addRoad(city1, city2, distance))
                    update(myGraph);
                if (myGraph.addRoad(city2, city1, distance))
                    update(myGraph);
            }
        }
        else if (choice == 3)
        {
            string DeletedCity;
            cout << "Enter the name of the new city that you want to delete it: \n";
            cin >> DeletedCity;

            if (myGraph.deleteCity(DeletedCity))
                update(myGraph);
        }
        else if (choice == 4)
        {
            string city1, city2;
            cout << "Deleing: \n\tCity 1: ";
            cin >> city1;
            cout << "\tCity 2: ";
            cin >> city2;

            if (myGraph.deleteRoad(city1, city2))
                update(myGraph);
        }
        else if (choice == 5)
            return;
        else
            cout << "invalid choice :/ \n";

    }while (true);
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
void addGraph(unordered_map<string, graph>& maps)
{
    string graphName;
    cout << "Map Name: ";
    cin >> graphName;

    graph newGraph(graphName);
    maps[graphName] = newGraph;
    cout << "Created your graph :)" << endl;
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
    vector<string> shortestPathVector;
    vector<float> distances;

    cout << endl << "Let's start our journey in finding the shortest path!" << endl
         << "Starting city is:";
    cin >> city1;
    cout << endl <<"Destination city is:";
    cin >> city2;
    theShortestDistance = Dijkstra(myMap, city1, city2, shortestPathVector,distances);
    if (theShortestDistance == -1.0)
    {
        cout << "=============================================================" << endl
            << "There is no path between  " << city1 << " and " << city2 << endl;
    }
    else
    {
        cout << "=============================================================" << endl
            << "The total distance of the shortest path between " << city1 << " and " << city2 << " is = " << theShortestDistance << endl;


        vector<string>::iterator pathIt = shortestPathVector.begin();
        vector<float>::iterator distancesIt = distances.begin();

        //to handle displayed errors
        int counter = 0;

        //display the path and distances 
        while (pathIt != shortestPathVector.end())
        {
            if (counter ==  shortestPathVector.size() - 1) 
            {
                cout << *pathIt << endl;
            } 
            else 
            {
                cout << *pathIt << " -> " << *distancesIt << " -> ";
                distancesIt++;
            }

            pathIt++;
            counter++;
        }

        cout << endl;
    }
}

/**
* intro - greeting the user (first thing the user sees)
*
* Retrun: nothing
*/
void intro(unordered_map<string, graph>& maps)
{
    cout << "\t\t\t\t\tWelcome to the Mini Wasalni program!" << endl;
    cout << "\t\t\t===================================================================" << endl;
    cout << "\t\t\t===================================================================" << endl;
    do {
        int mainChoice;
        cout << endl << endl << endl;
        cout << "\t\t\t\t\tHome Page" << endl;
        cout << "1. Add new map" << endl;
        cout << "2. Work on an existing map" << endl;
        cout << "3. Exit program" << endl;
        cout << "-> ";

        cin >> mainChoice;

        if (mainChoice == 1)
            addGraph(maps);

        else if (mainChoice == 2) 
        {
            if (maps.size() == 0)
                cout << "Sorry=( You don't have any map to work on please create a new map" << endl;
            else
                workOnMap(maps);
        }
        else if (mainChoice == 3)
        {
            // exit function goes here
            writeMultipleGraphs(maps, ".\\");
            cout << "Goodbye!" << endl;
            break;
        }

        else
            cout << "Invalid choice ,Please try again \n";
    } while (true);
}

void Traverse(graph& mygraph)
{
    string startCity;
    cout << "Starting From: ";
    cin >> startCity;

    string traverseChoice;
    cout << "DFS or BFS ?  -> ";
    cin >> traverseChoice;

    if (traverseChoice == "DFS")
        DFS(mygraph, startCity);

    else if (traverseChoice == "BFS")
        BFS(startCity, mygraph);

    else
        cout << "Invalid Choice please try again :(\n";
}

void workOnMap(unordered_map<string, graph>& maps)
{
    string mapName;
    bool mapExist=false;
    cout << "Which map ? \n" << "Available maps: ";
    // show the user all the maps
    for (auto& it : maps)
        cout << it.first << ' ';
    cout << endl;

    do {
        cin >> mapName;
        for (auto& it : maps)
        {
            if (mapName == it.first)
            {
                mapExist = true;
                break;
            }
        }
        if (mapExist)
            break;
        else
            cout << "Sorry=( This map dose not exist please enter another map name " << endl;

    } while (true);
    
    // check here that you have a valid map name

    do {
        int choice;
        cout << endl << endl << endl;
        cout << "\t\t\t\t\tWorking on " << mapName << endl;
        cout << "1. Display map data" << endl;
        cout << "2. Update map data" << endl;
        cout << "3. Traverse the map" << endl;
        cout << "4. Find shortest path" << endl;
        cout << "5. Home Page" << endl;
        cout << "===================================================================" << endl;

        cin >> choice;

        if (choice == 1)
            displayGraph(maps[mapName]);

        else if (choice == 2)
            update(maps[mapName]);

        else if (choice == 3)
            Traverse(maps[mapName]);

        else if (choice == 4)
            Find(maps[mapName]);

        else if (choice == 5)
            return;

        else
            cout << "Invalid choice. Please try again." << endl;

    } while (true);
}