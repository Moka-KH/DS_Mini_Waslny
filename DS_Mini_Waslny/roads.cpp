#include "roads.h"
#include "enumerators.cpp""

void addOrEditRoad(graph& myGraph)
{
    string city1, city2;
    float distance;
    cout << "Adding / Updating Road:\n" << "\tCity 1: ";
    cin >> city1;
    cout << "\tCity 2: ";
    cin >> city2;
    cout << "\tDistance: ";

    // get the distance input
    do {
        try {
            cin >> distance;
            // if we have string instead of numeric value
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw std::runtime_error("Invalid input =(\nPlease enter a numerical input");
            }
            // ensure that the distance is positive
            else if (distance <= 0)
                cout << "Please enter a psitive distance\n" << endl;
            else
                break;
        }
        catch (runtime_error& exp)
        {
            // just print the exception message
            cout << exp.what() << endl;
        }

    } while (true);

    // ask the user: Directed or Undirected ?
    int choice;
    cout << "One way or roundway Road ?\n"
        << "1- One way \t 2- Roundway   -> ";
    cin >> choice;

    if (choice == 1)
    {
        // ask the user for the direction
        cout << "1- from " << city1 << " to " << city2 << "\n"
            << "2- from " << city2 << " to " << city1 << "\n"
            << "-> ";
        cin >> choice;

        // add the road and call the messenger to give feedback
        int message;
        if (choice == 1)
        {
            message = myGraph.addRoad(city1, city2, distance);
            addRoadFeedback(city1, city2, message);
        }
        else if (choice == 2)
        {
            message = myGraph.addRoad(city2, city1, distance);
            addRoadFeedback(city2, city1, message);
        }
        else
            cout << "invalid choice :/\n";
    }
    else if (choice == 2)
    {
        int message1 = myGraph.addRoad(city1, city2, distance);
        addRoadFeedback(city1, city2, message1);

        int message2 = myGraph.addRoad(city2, city1, distance);
        addRoadFeedback(city2, city1, message2);
    }
}
void addRoadFeedback(string city1, string city2, int message)
{
    if (message == noCity1)
        cout << "Sorry! " << city1 << " doesn't exist" << endl;
    else if (message == noCity1)
        cout << "Sorry! " << city2 << " doesn't exist" << endl;
    else if (message == addedRoad)
        cout << "Added a road successfully =)" << endl;
    else if (message == updatedRoad)
        cout << "updated a road successfully =)" << endl;
}