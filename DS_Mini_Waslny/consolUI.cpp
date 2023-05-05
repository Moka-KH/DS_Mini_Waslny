#pragma once
#include<iostream>
#include "graph.h"
#include "algorithms.h"


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
    cout << "2. Add New Edge\n";
    cout << "3. Delete City\n";
    cout << "4. Delete Edge\n";
    cout << "5. Return to the Main\n";
    cin >> choice;

    switch (choice){
    case 1:
    {
        string AddedCity;
        bool cityExist;
        cout << "Enter the name of the new city that you want to add it: \n";
        cin >> AddedCity;
        cityExist = myGraph.checkCity(AddedCity, myGraph);
        if (cityExist) {
            int rechoice;
            cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
            cin >> rechoice;
            if (rechoice == 1) {
                update(myGraph);
            }
            if (rechoice == 2) {
                return;
            }
        }
        else
            myGraph.addCity(AddedCity);
        break;

    }
    case 2:
    {
        string city1, city2;
        float addedEdgeDistance;
        cout << "Enter the name of the two cities\n name of city number 1 is:\n";
        cin >> city1;
        cout << "name of city number 2 is:\n";
        cin >> city2;
        cout << "Enter the distance between them \n";
        cin >> addedEdgeDistance;

        bool city1Exist = myGraph.checkCity(city1, myGraph);
        bool city2Exist= myGraph.checkCity(city2, myGraph);
        if (city1Exist == true && city2Exist == true) {
            bool edgeExist = myGraph.checkEdge(city1, city2, myGraph);
            if (edgeExist) {
                int rechoice;
                cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
                cin >> rechoice;
                if (rechoice == 1) {
                    update(myGraph);
                }
                if (rechoice == 2) {
                    return;
                }
            }
            else
                myGraph.addRoad(city1,city2, addedEdgeDistance);

        }
        break;

    }
    case 3:
    {
        string DeletedCity;
        bool cityExist;
        cout << "Enter the name of the new city that you want to delete it: \n";
        cin >> DeletedCity;
        cityExist = myGraph.checkCity(DeletedCity, myGraph);
        if (cityExist) 
            myGraph.deleteCity(DeletedCity, myGraph);
        else {
            int rechoice;
            cout << "This city is not exist exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
            cin >> rechoice;
            if (rechoice == 1) {
                update(myGraph);
            }
            if (rechoice == 2) {
                return;
            }
        }
        break;
    }
    case 4:
    {
        string city1, city2;
        cout << "Enter the name of the two cities\n name of city number 1 is:\n";
        cin >> city1;
        cout << "name of city number 2 is:\n";
        cin >> city2;

        bool city1Exist = myGraph.checkCity(city1, myGraph);
        bool city2Exist = myGraph.checkCity(city2, myGraph);
        if (city1Exist == true && city2Exist == true) {
            bool edgeExist = myGraph.checkEdge(city1, city2, myGraph);
            if (edgeExist)
                myGraph.deleteRoad(city1, city2, myGraph);
            else {
                int rechoice;
                cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
                cin >> rechoice;
                if (rechoice == 1) {
                    update(myGraph);
                }
                if (rechoice == 2) {
                    return;
                }
            }


        }
        break;
    }
    case 5: 
        return;
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
    cout << " Your Graph is created sucsessfully," << endl
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
    cin  >> city1;
    cout << "Now, Please enter Your destination city," <<endl
         << "Your destination city is:";
    cin >> city2;
    vector<string> shortestPathVector;
    shortestPathVector = Dijkstra(myMap, city1, city2, theShortestDistance);
    
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