#pragma once
#include <Windows.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include "graph.h"
#include "homePage.h"
#include "dashboard.h"
#include "files.h"

using namespace std;

/**
* @brief greeting the user (first thing the user sees)
*
* @param maps a reference to the hash table containing all the maps
* @return void
*/
void homePage(unordered_map<string, graph>& maps)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    system("cls");  // clear the console
    cout << "\t\t\t\t\tWelcome to the Mini Wasalni program!" << endl;
    cout << "\t\t\t===================================================================" << endl;
    cout << "\t\t\t===================================================================" << endl;
    while (true)
    {
        int choice;
        cout << endl << endl << endl;
        cout << "\t\t\t\t\tHome Page" << endl;
        cout << "1. Add new map" << endl;
        cout << "2. Maps Dashboards" << endl;
        cout << "3. Exit program" << endl;
        cout << "-> ";

        cin >> choice;
        system("cls");  // clear the console

        if (choice == 1)
            addMap(maps);

        else if (choice == 2)
            mapsDashboard(maps);

        else if (choice == 3)
        {
            writeMultipleGraphs(maps, ".\\");
            cout << "Goodbye!" << endl;
            return;
        }

        else
            cout << "Invalid choice ,Please try again \n";
    }
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
        cout << "\t\t\t\t\t\"" << mapName << "\" Dashboard" << endl;
        cout << "1. Display map data" << endl;
        cout << "2. Update map data" << endl;
        cout << "3. Traverse the map" << endl;
        cout << "4. Path Finder" << endl;
        cout << "5. Home Page" << endl;
        cout << "===================================================================" << endl;

        cin >> choice;
        system("cls");   // clear the console

        if (choice == 1)
            maps[mapName].display();

        else if (choice == 2)
            updateMap(maps[mapName], mapName);

        else if (choice == 3)
            Traverse(maps[mapName]);

        else if (choice == 4)
            pathFinder(maps[mapName]);

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
    cout << "Which map ?\n" << "Available maps: ";

    // show the user all the maps
    for (auto& map : maps)
        cout << map.first << "\n\t";
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

/**
* This function takes an integer as an input from the user but makes sure it's an integer
* it it's not an integer, it keeps asking them to input a number 
* 
* @return the inputted integer
*/
float validateFloat()
{
    string input;
    bool validInput;
    short pointsCounter; // counts the floating points in the input
    while (true)
    {
        validInput = true;
        pointsCounter = 0;
        cin >> input;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '.')
                pointsCounter++;

            validInput = (isdigit(input[i]) || input[i] == '.') && pointsCounter <= 1;
            if (!validInput)
            {
                cout << "Please Enter a \"Positive Numeric Value\":\n-> ";
                break;
            }
        }

        if (validInput)
            break;
    }

    // stof -> cast provided string to float
    return stof(input);
}