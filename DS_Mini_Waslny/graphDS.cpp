#include <iostream>
#include "graphDS.h"
#include <string.h>
#include <utility>  // for pairs
#include <unordered_map>
#include <list>

using namespace std;


/*
	* Notes:
	* map.begin() -> returns an iterator to the first element in the map
	* map.end() -> returns an iterator pointing to past the last element of the map.
	*			   Since it does not refer to a valid element, it cannot de-referenced
	* map.at() -> returns a pointer to the value
	* map.insert() -> adds a new bucket(key & value)
	* map.find() -> returns an iterator pointing to the vertex if it exists
	*				and returns map.end() (not a bucket) if it doesn't exist.
	* map.erase() -> return 1 if found key and erase it otherwise return 0
*/

/**
* graphDS - the graph constructor
* 
* Description: sets the #vertices to zero
* 
* Return: nothing
*/
graphDS::graphDS()
{
	vertexNum = 0;
}

/**
* getVertexNum - returns #vertices
* Return: integer value -> #vertices
*/
int graphDS::getVertexNum()
{
	return vertexNum;
}

/**
* addCity - Adds a new City
* @newCity: City Name
* 
* Description: if the city already exists, it gives an Error Message
*			   else it adds a new vertex for the city with an empty list of 
*			   adjacent vertices
* 
* Return: nothing
*/
void graphDS::addCity(string newCity)
{
	mapIterator = map.find(newCity);
		
	// if it already exists
	if (mapIterator != map.end())
		cout << "City " << newCity << "already exists = | \n";
	else //add the new city
	{
		//empty list
		list <pair <string, int>> newList;

		//make new list for the new city
		map[newCity] = newList;

		//increment number of cities
		vertexNum++;

		cout << newCity << " is Added Successfully =)\n";
	}
}

/**
* addCity - Adds a new City and connects it with another on
*			with a given distance
* @newCity: City Name to be added
* @adjCity: City Name to be connected with
* @distance: Distance
*
* Description: if the city already exists, it gives an Error Message
*			   else it adds a new vertex for the city and calls addRoad()
*			   to connect them
*
* Return: nothing
*/
void graphDS::addCity(string newCity, string adjCity, int distance)
{
	mapIterator = map.find(newCity);

	bool validInput = true;
	// if the vetex to be added already exists
	if (mapIterator != map.end())
	{
		cout << "City " << newCity << " already exists =| \n";
		validInput = false;
	}
	// if the vertex we'r connecting to doesn't exist
	if (map.find(adjCity) == map.end())
	{
		cout << "City " << adjCity << " doesn't exist. You can't link to it\n";
		validInput = false;
	}
	
	// add the new city
	if (validInput)
	{
		// empty list
		list <pair <string, int>> newList;
		// make new list for the new city
		map[newCity] = newList;
		addRoad(newCity, adjCity, distance);
	}
}

/**
* addRoad - Connects 2 cities
* @city1: first city
* @city2: second city
* @distance: Distance
*
* Description: makes sure both of them exist.
*			   if so, adds the road
*
* Return: nothing
*/
void graphDS::addRoad(string city1, string city2, int distance)
{

	bool validInput = true;
	// if the first one doesn't exist
	if (map.find(city1) == map.end())
	{
		cout << "City: " << city1 << " doesn't exist\n";
		validInput = false;
	}
	// if the second one doesnt exist
	if (map.find(city2) == map.end())
	{
		cout << "City: " << city2 << " doesn't exist\n";
		validInput = false;
	}

	// ===  both exist :) add the road  ===
	if (validInput)
	{
		// keep the city to be connected to & distance in a pair holder
		pairHolder.first = city2;
		pairHolder.second = distance;

		// then add this pair holder to the linked list
		map.at(city1).push_back(pairHolder);
	}
}

/**
* deleteCity - Deletes a City
* @cityName: City Name to be deleted
*
* Description: if the city doesn't exist, it gives an Error Message
*			   else it removes the city vertex and the list of
*			   adjacent vertices
*
* Return: nothing
*/
void graphDS::deleteCity(string cityName)
{
	// erase city if exists otherwise, show message
	if (map.erase(cityName) != 1)
	{
		cout << "The city you have entered does not exist :(\n"
			<< "Make sure you wrote the name right\n";
		return;
	}
	//decrement number of cities
	vertexNum--;
}

/**
* deleteRoad - deletes a road between 2 cities
* @city1: first city
* @city2: second city
* 
* Description: first makes sure that cities exist. if so,
*			   it searches in city1 connections for city2,
*			   if it isn't there, gives a message NO edge between them
*			   else (it's there), it deletes it
* 
*			   note: it assumes the graph is undirected
* 
* Return: nothing
*/
void graphDS::deleteRoad(string city1, string city2)
{
	// if at least one city doesn't exist
	if (map.find(city1) == map.end())
	{
		cout << city1 << " doesn't exist :|\n";
		return;
	}
	else if (map.find(city2) == map.end())
	{
		cout << city2 << " doesn't exist :|\n";
		return;
	}
	else // cities exist. Search for city2 in city1 connections
	{
		listIterator = map.at(city1).begin(); // search starting point

		list <pair <string, int>>::iterator listEnd;
		listEnd = map.at(city1).end(); // search breaking point

		if (listIterator == listEnd)
		{
			map.at(city1).erase(listIterator);  // erase gives an exception :(
			cout << "deleted it :)\n";
			return;
		}
		for (; listIterator != listEnd; listIterator++)
		{
			if ((*listIterator).first == city2) // when you find it, delete it
			{
				map.at(city1).erase(listIterator); // erase gives an exception :(
				return;
			}
		}
		// reaching here means city1 & city2 are not connected
		cout << city1 << " & " << city2 << " are not ajacent :|";
	}
}

void graphDS::display()
{
	cout << "\nElements : \n";
	//display the key value once
	for (mapIterator = map.begin(); mapIterator != map.end(); mapIterator++)
	{
		// itr works as a pointer to a bucket
		// itr->first stores the key part and
		// itr->second stores the value part

		cout << mapIterator->first << endl;

		//display the linked list compmnents "the value of the map's key"
		for (listIterator = mapIterator->second.begin(); listIterator != mapIterator->second.end(); ++listIterator)
		{
			cout << (*listIterator).first << "  " << (*listIterator).second << endl;
		}
		cout << "\t\t\t=====================================" << endl;
	}
}

graphDS :: ~graphDS()
{
	map.clear();
}