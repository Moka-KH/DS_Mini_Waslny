#include "graph.h"
#include "updateMap.h"
#include "homePage.h"
#include "enumerators.cpp"
#include "coloredOutput.cpp"

// This file has functions that separate the messages from the graph class functions
// in order to make the data loading in the beginning of the program silent

/**
* This function adds the city to the provided graph and based on the return value
* of addCity(), it displays a feedback message
* 
* @param myGraph the graph to add the city to
* @return void
*/
void addCity(graph& myGraph)
{
    successMessage("\t\tAdding a City\n");
    cout << "\tName: ";
    string city;
    cin >> city;

    int message = myGraph.addCity(city);

    if (message == cityExists)
        failureMessage(city + " city" + " already exists =|\n");
    else if (message == success)
        successMessage("Added \"" + city + "\" =)\n");
}

/**
* This function lets the user add / edit a road.. it uses the the addRoad function from
* the graph class and calls addRoadFeedback() which handles the feedback messages that appear
* to the user
* 
* @param myGraph the graph to add / edit its roads
* @return void
*/
void addOrEditRoad(graph& myGraph)
{
    string city1, city2;
    float distance;
    successMessage("Adding / Updating Road:\n");
    cout << "\tCity 1: ";
    cin >> city1;
    cout << "\tCity 2: ";
    cin >> city2;   
    cout << "\tDistance: ";
    
    // input valid distance
    while (true)
    {
        // validate it's a number
        distance = validateFloat();

        // validate it's positive
        if (distance <= 0)
            failureMessage("please enter a psitive distance\n");
        else
            break;
    }

    // ask the user: Directed or Undirected ?
    int choice;
    cout << "One way or roundway Road ?\n"
        << "1- One way \t 2- Roundway\n-> ";
    cin >> choice;

    if (choice == 1)
    {
        // ask the user for the direction
        cout << "1- from " << city1 << " to " << city2 << "\n"
            << "2- from " << city2 << " to " << city1 << "\n"
            << "-> ";
        cin >> choice;

        // add the road and call addRoadFeedback() to give feedback
        int message;
        if (choice == 1)
        {
            message = myGraph.addEditRoad(city1, city2, distance);
            addRoadFeedback(city1, city2, message);
        }
        else if (choice == 2)
        {
            message = myGraph.addEditRoad(city2, city1, distance);
            addRoadFeedback(city2, city1, message);
        }
        else
            failureMessage("invalid choice :/\n");
    }
    else if (choice == 2)
    {
        int message1 = myGraph.addEditRoad(city1, city2, distance);
        addRoadFeedback(city1, city2, message1);

        int message2 = myGraph.addEditRoad(city2, city1, distance);
        //addRoadFeedback(city2, city1, message2);
    }
    else
        failureMessage("invalid choice :/\n");
}

/**
* this function prints a message in the console depending on the given message parameter
* 
* @param city1 city1 name
* @param city2 city2 name
* @param message the return value form calling addRoad() function in the graph class
* @return void
*/
void addRoadFeedback(string city1, string city2, int message)
{
    if (message == noCity1)
        failureMessage("Sorry! " + city1 + " doesn't exist =|\n");
    else if (message == noCity2)
        failureMessage("Sorry! " + city2 + " doesn't exist =|\n");
    else if (message == addedRoad)
        successMessage("Road between " + city1 + " and " + city2 + " is Added successfully =)\n");
    else if (message == updatedRoad)
        successMessage("Road between " + city1 + " and " + city2 + " is Updated successfully = )\n");
}

/**
* This function lets the user delete a road.. it uses the the deleteRoad function from
* the graph class and calls deleteRoadFeedback() which handles the feedback messages that appear
* to the user
*
* @param myGraph the graph to delete its roads
* @return void
*/
void deleteRoad(graph& myGraph)
{
    string city1, city2;
    successMessage("Deleing Road:\n");
    cout << "\tCity 1: ";
    cin >> city1;
    cout << "\tCity 2: ";
    cin >> city2;

    int message = myGraph.deleteRoad(city1, city2);
    deleteRoadFeedback(city1, city2, message);
}

/**
* this function prints a message in the console depending on the given message parameter
*
* @param city1 city1 name
* @param city2 city2 name
* @param message the return value form calling deleteRoad() function in the graph class
* @return void
*/
void deleteRoadFeedback(string city1, string city2, int message)
{
    switch (message)
    {
    case NoCity1:
        cout << '\"' << city1 << "\" doesn't exist =|\n";
        break;
    case NoCity2:
        failureMessage('\"' + city2 + "\" doesn't exist =|\n");
        break;
    case noRoad:
        failureMessage("There is no road between " + city1 + " and " + city2 + " =(\n");
        break;
    case Rdeleted:
        successMessage("Road is deleted =)\n");
        break;
    }
}

/**
* This function lets the user delete a city.. it uses the the deleteCity function from
*and handle messages that appears to user
* @param myGraph the graph to delete its city
* @return void
*/
void deleteCity(graph& myGraph)
{
    string city;
    successMessage("Delete the City: ");
    cin >> city;

    int message = myGraph.deleteCity(city);
    if (message == noCity)
        failureMessage("city " + city + " does not exist =(\n");
    else
        successMessage("City is deleted =)\n");
}