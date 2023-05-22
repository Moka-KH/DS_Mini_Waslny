#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "graph.h"
#include "coloredOutput.cpp"
#include "homePage.h"
#include "dashboard.h"
#include "files.h"
#include <chrono>
#include <thread>

using namespace std;

/**
* @brief greeting the user (first thing the user sees)
*
* @param maps a reference to the hash table containing all the maps
* @return void
*/
void homePage(unordered_map<string, graph>& maps)
{
    // color the console and clear it
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
    system("cls");

    string welcomeMessage = "\t\t\t\t\tWelcome to the Mini Wasalni program!\n"
    "\t\t\t===================================================================\n"
    "\t\t\t===================================================================\n";
    successMessage(welcomeMessage);

    while (true)
    {
        int choice;
        cout << endl << endl << endl;
        cout << "\t\t\t\t\t\t\tHome Page" << endl;
        cout << "1. Add new map" << endl;
        cout << "2. Maps Dashboards" << endl;
        cout << "3. Delete existing map" << endl;
        cout << "4. Exit program" << endl;
        cout << "-> ";

        cin >> choice;
        // clear the console
        system("cls");

        if (choice == 1)
            addMap(maps);

        else if (choice == 2)
            mapsDashboard(maps);

        else if (choice == 3)
            deleteMap(maps);

        else if (choice == 4)
        {
            writeMultipleGraphs(maps, ".\\");
            successMessage("\t\t\t\t\t\tGOODBYE MI AMIGAS =)\n");
            return;
        }

        else
            failureMessage("Invalid choice ,Please try again \n");
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
        bool found = false;
        cout << "Map Name: ";
        cin >> mapName;
        for (auto& map : maps)
        {
            if (mapName == map.first)
            {
                failureMessage("There is already a map with this name.. Please choose another name\n");
                found = true;
                continue;
            }
        }
        if (found)
            continue;
        else
            break;
    } 


    // create a new map
    graph newMap(mapName);
    maps[mapName] = newMap;
    successMessage("Created a graph for you =)\n");
}

/**
* @brief This function delete an exsisting map
*
* @param maps a reference to the hash table containing all the maps in the program
* @return void
*/
void deleteMap(unordered_map<string, graph>& maps)
{
    string mapName;

    // validate the input (map name) is exist
    while (true)
    {
        bool found = false;
        cout << "Map Name: ";
        cin >> mapName;
        for (auto& map : maps)
        {
            if (mapName == map.first)
            {
                maps.erase(mapName);
                successMessage("Your map is deleted successfully =)\n");
                found = true;
                break;
            }
        }
        if (found)
            break;
        else 
        {
            failureMessage("This map dosen't exist.. Please choose an existing map name\n");
            continue;
        }
    }

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
        cout << endl;
        successMessage("\t\t\t\t\t\"" + mapName + "\" Dashboard\n");
        cout << "1. Display map data" << endl;
        cout << "2. Update map data" << endl;
        cout << "3. Traverse the map" << endl;
        cout << "4. Path Finder" << endl;
        cout << "5. Home Page" << endl;
        cout << "===================================================================" << endl;

        cin >> choice;
        // clear the console
        system("cls");   

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
            failureMessage("Invalid choice. Please try again.\n");
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
        failureMessage("Sorry =( You don't have any maps.. please create a new map\n");
        std::this_thread::sleep_for(std::chrono::seconds(3));
        homePage(maps);
        return "";
    }
    
    string mapName;
    cout << "Which map ?\n" << "Available maps: ";

    // show the user all the maps
    for (auto& map : maps)
        cout << "\n\t" << map.first;
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
            failureMessage("Sorry =( This map doesn't exist please enter another map name\n");
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
                failureMessage("Please Enter a \"Positive Numeric Value\":\n-> ");
                break;
            }
        }

        if (validInput)
            break;
    }

    // stof -> cast provided string to float
    return stof(input);
}