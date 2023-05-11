#include "dashboard.h"

//       update = add city + add/edit road + delete city + delete road + Dashboard again
/**
 * @brief This function allows the user to update the graph data structure by adding new cities,
 *        adding new edges between existing cities, deleting existing cities, or deleting edges between existing cities.
 *
 * @param myGraph a reference to the graph data structure that the user wants to update.
 * @retun void
 */
void updateMap(graph& myGraph)
{
    int choice;
    do
    {
        cout << "\t\t\t\t\tUpdating " << myGraph.name << endl;
        cout << "1. Add City\n";
        cout << "2. Add / Edit a Road\n";
        cout << "3. Delete City\n";
        cout << "4. Delete Road\n";
        cout << "5. Return to the " << myGraph.name << " Dashboard\n";
        cin >> choice;

        if (choice == 1)
        {
            string AddedCity;
            cout << "\tName: ";
            cin >> AddedCity;

            if (myGraph.addCity(AddedCity))
                updateMap(myGraph);
        }
        else if (choice == 2)
        {
            addOrEditRoad(myGraph);
        }
        else if (choice == 3)
        {
            string DeletedCity;
            cout << "Enter the name of the new city that you want to delete it: \n";
            cin >> DeletedCity;

            if (myGraph.deleteCity(DeletedCity))
                updateMap(myGraph);
        }
        else if (choice == 4)
        {
            string city1, city2;
            cout << "Deleing: \n\tCity 1: ";
            cin >> city1;
            cout << "\tCity 2: ";
            cin >> city2;

            if (myGraph.deleteRoad(city1, city2))
                updateMap(myGraph);
        }
        else if (choice == 5)
            return;
        else
            cout << "invalid choice :/ \n";

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
    cout << endl << "Destination city is:";
    cin >> city2;
    theShortestDistance = Dijkstra(myMap, city1, city2, shortestPathVector, distances);
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
            if (counter == shortestPathVector.size() - 1)
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