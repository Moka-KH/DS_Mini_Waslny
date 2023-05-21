#include <stack>
#include "dashboard.h"
#include "updateMap.h"
#include "Algorithms.h"

/**
 * This function allows the user to update the map by adding new cities and roads,
 * and deleting existing cities or edges between existing cities.
 *
 * @param myGraph a reference to the graph data structure that the user wants to update.
 * @retun void
 */
void updateMap(graph& myGraph, string mapName)
{
    int choice;
    while (true)
    {
        cout << "\t\t\t\t\tUpdating " << mapName << endl;
        cout << "1. Add a City\n";
        cout << "2. Add / Edit a Road\n";
        cout << "3. Delete a City\n";
        cout << "4. Delete a Road\n";
        cout << "5. Return to " << mapName << " Dashboard\n";

        cin >> choice;
        system("cls"); // clear the console

        if (choice == 1)
            addCity(myGraph);

        else if (choice == 2)
            addOrEditRoad(myGraph);

        else if (choice == 3)
            deleteCity(myGraph);

        else if (choice == 4)
            deleteRoad(myGraph);

        else if (choice == 5)
            return;

        else
            cout << "invalid choice :/ \n";
    }
}

/**
 * Traverses the graph starting from a specified city using 
 * either DFS (Depth-First Search) or BFS (Breadth-First Search).
 *
 * @param mygraph The graph to traverse.
 * 
 * @return void
 */
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

/**
* This function finds the shortest path between two cities in a graph
* using Dijkstra's algorithm and display the path and distances between 
* them using displayPathFinder().
*
* @param myMap A reference to the graph object containing cities and roads.
* @return void.
*/
void pathFinder(graph& myMap)
{   
    string startingCity, targetCity;
    float totalDistance;
    stack<pair<string, float>> path;

    cout << "Path Finder:" << endl << "\tStarting city: ";
    cin >> startingCity;
    cout << "\tDestination city: ";
    cin >> targetCity;

    totalDistance = Dijkstra(myMap, startingCity, targetCity, path);

    // Check if a path exists between the cities
    if (totalDistance == -1.0)
        cout << "There is no path between " << startingCity << " and " << targetCity << "=|\n";
    else
    {
        cout << "From " << startingCity << " to " << targetCity << " -> " << totalDistance << endl;

        displayPath(path, startingCity);
    }
}

/**
 * Displays the shortest path and corresponding distances between cities.
 *
 * @param shortestPath The vector containing the cities in the shortest path.
 * @param pathDistances The vector containing the distances between consecutive cities in the shortest path.
 *
 * @return void.
 */
void displayPath(stack<pair<string, float>> path, string startingCity)
{
    cout << startingCity;
    while (!path.empty())
    {
        cout << " -> " << path.top().second << " -> " << path.top().first;
        path.pop();
    }
}
