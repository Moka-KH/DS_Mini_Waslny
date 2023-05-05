#pragma once
#include<iostream>
#include "graph.h"
#include"main.cpp"

using namespace std;

//enum updateEnum {
//	addCity, addEdge, deleteCity, deleteEdge, exit
//};

void update(graph& myGraph) {
	
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
        cityExist = myGraph.checkCity(AddedCity);
        if (cityExist) {
            int rechoice;
            cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
            cin >> rechoice;
            if (rechoice == 1) {
                update(myGraph);
            }
            if (rechoice == 2) {
                main();
            }
        }
        else
            myGraph.addCity(AddedCity);
        break;

    }
    case 2:
    {
        string city1, city2;
        int addedDistance;
        cout << "Enter the name of the two cities\n name of city number 1 is:\n";
        cin >> city1;
        cout << "name of city number 2 is:\n";
        cin >> city2;
        cout << "Enter the distance between them \n";
        cin >> addedDistance;

        bool city1Exist = myGraph.checkCity(city1);
        bool city2Exist= myGraph.checkCity(city2);
        if (city1Exist == true && city2Exist == true) {
            bool edgeExist = myGraph.checkEdge(city1, city2);
            if (edgeExist) {
                int rechoice;
                cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
                cin >> rechoice;
                if (rechoice == 1) {
                    update(myGraph);
                }
                if (rechoice == 2) {
                    main();
                }
            }
            else
                myGraph.addRoad(city1,city2, addedDistance);

        }
        break;

    }
    case 3:
    {
        string DeletedCity;
        bool cityExist;
        cout << "Enter the name of the new city that you want to delete it: \n";
        cin >> DeletedCity;
        cityExist = myGraph.checkCity(DeletedCity);
        if (cityExist) 
            myGraph.deleteCity(DeletedCity);
        else {
            int rechoice;
            cout << "This city is not exist exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
            cin >> rechoice;
            if (rechoice == 1) {
                update(myGraph);
            }
            if (rechoice == 2) {
                main();
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

        bool city1Exist = myGraph.checkCity(city1);
        bool city2Exist = myGraph.checkCity(city2);
        if (city1Exist == true && city2Exist == true) {
            bool edgeExist = myGraph.checkEdge(city1, city2);
            if (edgeExist)
                myGraph.deleteRoad(city1, city2);
            else {
                int rechoice;
                cout << "This city is already exist \n Enter 1 to update again OR Enter 2 to return to the main menu\n";
                cin >> rechoice;
                if (rechoice == 1) {
                    update(myGraph);
                }
                if (rechoice == 2) {
                    main();
                }
            }


        }
        break;
    }
    case 5: {

    }
    
    }
      

	

}

void displayGraph() {


}

void addGraph() {


}

void Find() {


}