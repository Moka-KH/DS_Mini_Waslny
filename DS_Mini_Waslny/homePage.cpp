#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "homePage.h"
#include "files.h"
#include "enumerators.cpp"
#include "roads.h"
#include "dashboard.h"

using namespace std;

/**
* @brief greeting the user (first thing the user sees)
*
* @param maps a reference to the hash table containing all the maps
* @return void
*/
void homePage(unordered_map<string, graph>& maps)
{
    cout << "\t\t\t\t\tWelcome to the Mini Wasalni program!" << endl;
    cout << "\t\t\t===================================================================" << endl;
    cout << "\t\t\t===================================================================" << endl;
    do {
        int choice;
        cout << endl << endl << endl;
        cout << "\t\t\t\t\tHome Page" << endl;
        cout << "1. Add new map" << endl;
        cout << "2. Maps Dashboards" << endl;
        cout << "3. Exit program" << endl;
        cout << "-> ";

        cin >> choice;

        if (choice == 1)
            addMap(maps);

        else if (choice == 2)
            mapsDashboard(maps);

        else if (choice == 3)
        {
            cout << "Goodbye!" << endl;
            return;
        }

        else
            cout << "Invalid choice ,Please try again \n";
    } while (true);
}

/**
* @brief This function creates a new map
* 
* @param maps a reference to the hash table containing all the maps in the program
* @return void
*/
void addMap(unordered_map<string, graph>& maps)
{
    string mapName;
    
    // validate the input (map name)
    while (true)
    {
        cout << "Map Name: ";
        cin >> mapName;
        for (auto& map : maps)
        {
            if (mapName == map.first)
            {
                cout << "There is already a map with this name.. Please choose another name\n";
                continue;
            }
        }
        break;
    }    

    // create a new map
    graph newMap(mapName);
    maps[mapName] = newMap;
    cout << "Created a graph for you =)" << endl;
}

/**
* This function takes a map name from the user and works as a map dashboard
* (gives them the options to work on the chosen map)
* 
* @param maps a reference to the hash table containing all the maps in the program
* @return void
*/
void mapsDashboard(unordered_map<string, graph>& maps)
{
    string mapName = chooseMapDashboard(maps);
    
    int choice;
    while (true) {
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t" << mapName << " Dashboard" << endl;
        cout << "1. Display map data" << endl;
        cout << "2. Update map data" << endl;
        cout << "3. Traverse the map" << endl;
        cout << "4. Path Finder" << endl;
        cout << "5. Home Page" << endl;
        cout << "===================================================================" << endl;

        cin >> choice;

        if (choice == 1)
            maps[mapName].display();

        else if (choice == 2)
            updateMap(maps[mapName]);

        else if (choice == 3)
            Traverse(maps[mapName]);

        else if (choice == 4)
            Find(maps[mapName]);

        else if (choice == 5)
            return;

        else
            cout << "Invalid choice. Please try again." << endl;
    }
}

/**
* takes a map name from the user as an input and handles any invalid input
* 
* @param maps the hash table containing all the maps in the program
* @return the valid map name that the user has inputted
*/
string chooseMapDashboard(unordered_map<string, graph>& maps)
{
    if (maps.size() == 0)
    {
        cout << "Sorry =( You don't have any maps.. please create a new map" << endl;
        homePage(maps);
        return "";
    }
    
    string mapName;
    cout << "Which map ? \n" << "Available maps: ";

    // show the user all the maps
    for (auto& map : maps)
        cout << map.first << ' ';
    cout << endl;

    // make the user choose a map name (prevents null & non-existing names)
    bool mapExist = false;
    while (true)
    {
        cout << "Choose Map: ";
        cin >> mapName;

        if (mapName == "")
            continue;

        // iterate over the existing maps and decide whether the input name is one of them or not
        for (auto& map : maps)
        {
            if (mapName == map.first)
            {
                mapExist = true;
                break;
            }
        }

        // if it was one of them, get out of the loop (this will continue to the dashboard menu
        if (mapExist)
            return mapName;
        else
            cout << "Sorry =( This map doesn't exist please enter another map name" << endl;
    }
}