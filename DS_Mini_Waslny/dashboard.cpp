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
void updateMap(graph& myGraph)
{
    int choice;
    while (true)
    {
        cout << "\t\t\t\t\tUpdating " << myGraph.name << endl;
        cout << "1. Add a City\n";
        cout << "2. Add / Edit a Road\n";
        cout << "3. Delete a City\n";
        cout << "4. Delete a Road\n";
        cout << "5. Return to \"" << myGraph.name << "\" Dashboard\n";
        cin >> choice;

        if (choice == 1)
            addCity(myGraph);

        else if (choice == 2)
            addOrEditRoad(myGraph);

        else if (choice == 3)
        {
            string city;
            cout << "Delete the City: ";
            cin >> city;

            myGraph.deleteCity(city);
        }

        else if (choice == 4)
        {
            string city1, city2;
            cout << "Deleing Road: \n";
            cout << "\tCity 1: ";
            cin >> city1;
            cout << "\tCity 2: ";
            cin >> city2;

            myGraph.deleteRoad(city1, city2);
        }

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
* using Dijkstra's algorithm.
*
* @param myMap A reference to the graph object containing cities and roads.
* @return void.
*/
void pathFinder(graph& myMap)
{   
    string startingCity, destinationCity;
    float shortestDistance;
    vector<string> shortestPath;
    vector<float> pathDistances;

    // Prompt user for starting and destination cities
    cout << endl << "Let's start our journey in finding the shortest path!" << endl << "Starting city is:";
    cin >> startingCity;
    cout << endl << "Destination city is:";
    cin >> destinationCity;

    // Call Dijkstra's algorithm to calculate the shortest path and distance
    shortestDistance = Dijkstra(myMap, startingCity, destinationCity, shortestPath, pathDistances);

    // Check if a path exists between the cities
    if (shortestDistance == -1.0)
    {
        cout << "=============================================================" << endl
             << "There is no path between " << startingCity << " and " << destinationCity << endl;
    }
    else
    {
        cout << "=============================================================" << endl
             << "The total distance of the shortest path between " << startingCity << " and " << destinationCity << " is = " << shortestDistance << endl;

        // Iterators for traversing the shortest path and distances vectors
        vector<string>::iterator pathIt = shortestPath.begin();
        vector<float>::iterator distancesIt = pathDistances.begin();

        // Counter to handle displayed errors
        int counter = 0;

        // Display the path and distances
        while (pathIt != shortestPath.end())
        {
            if (counter == shortestPath.size() - 1)
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
