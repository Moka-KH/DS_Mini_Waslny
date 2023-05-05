#pragma once
#include <iostream>
#include <string.h>
#include <utility>
#include <unordered_map>
#include <list>
#include "graph.h"

using namespace std;


/*
	* Notes:
	* map.at() -> returns a pointer to the value
	* map.insert() -> adds a new key-value
	* map.find() -> return an iterator pointing to the vertex if it exists
	*				and to the last vertex if it doesn't
	* map.erase() -> return 1 if found key and erase it otherwise return 0
*/

/**
* graph - the graph constructor
*
* Description: sets the #vertices to zero
*
* Return: nothing
*/
graph::graph()
{
	vertexNum = 0;
}

/**
* getVertexNum - returns #vertices
* Return: integer value -> #vertices
*/
int graph::getVertexNum()
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
* Return: 0 when it ends successfully, 1 otherwise
*/
int graph::addCity(string newCity)
{
	// if it already exists
	if (checkCity(newCity))
	{
		cout << "City " << newCity << "already exists =| \n";
		return 1;
	}
		
	//add the new city and give it a list as a value in the map
	list <pair <string, float>> newList;
	map[newCity] = newList;
	vertexNum++;

	cout << newCity << " is Added Successfully =)\n";
	return 0;
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
* Return: 0 when it ends successfully, 1 otherwise
*/
int graph::addCity(string newCity, string adjCity, float distance)
{
	// if the vetex to be added already exists
	if (checkCity(newCity))
	{
		cout << "City " << newCity << " already exists =| \n";
		return 1;
	}

	// if the vertex we'are connecting to doesn't exist
	if (!checkCity(adjCity))
	{
		cout << "City " << adjCity << " doesn't exist. You can't link to it\n";
		return 1;
	}

	// reaching here means the input is valid

	// add the new city and give it a list as a value in the map
	list <pair <string, float>> newList;
	map[newCity] = newList;
	
	// link it with city2
	addRoad(newCity, adjCity, distance);
	return 0;
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
* Return: 0 when it ends successfully, 1 otherwise
*/
int graph::addRoad(string city1, string city2, float distance)
{
	// if the first one doesn't exist
	if (!checkCity(city1))
	{
		cout << "City: " << city1 << " doesn't exist\n";
		return 1;
	}
	// if the second one doesnt exist
	if (!checkCity(city2))
	{
		cout << "City: " << city2 << " doesn't exist\n";
		return 1;
	}

	// ===  both exist :) add the road  ===
	// put city2 in city1 conncections
	pairHolder.first = city2;
	pairHolder.second = distance;
	map.at(city1).push_back(pairHolder);

	// put city1 in city2 conncections
	pairHolder.first = city1;
	map.at(city2).push_back(pairHolder);

	return 0;
}

/**
* deleteCity - Deletes a City
* @cityName: City Name to be deleted
*
* Description: if the city doesn't exist, it gives an Error Message
*			   else it removes the list of adjacent vertices
*			   and finally removes the node itself
*
* Return: 0 when it ends successfully, 1 otherwise
*/
int graph::deleteCity(string cityName)
{
	if (!checkCity(cityName))
	{
		cout << "city " << cityName << " does not exist.. I can't delete it :(\n"
			<< "Make sure you wrote the name right\n";
		return 1;
	}

	// reaching here means it exists
	// delete its adjacent cities
	list<pair <string, float>> adjacent;
	getAdjacentList(cityName, adjacent);
	for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++)
		deleteRoad(cityName, listIterator->first );

	// remove city 
	map.erase(cityName);
	vertexNum--;

	return 0;
}

/**
* deleteRoad - deletes a road between 2 cities
* @city1: first city
* @city2: second city
*
* Description: first makes sure that cities exist. if so,
*			   it makes sure they're conncected. if so,
*			   it deletes the connection
*
* Return: 0 when it ends successfully, 1 otherwise
*/
int graph::deleteRoad(string city1, string city2)
{
	// if at least one city doesn't exist
	if (!checkCity(city1))
	{
		cout << city1 << " doesn't exist :|\n";
		return 1;
	}
	if (!checkCity(city2))
	{
		cout << city2 << " doesn't exist :|\n";
		return 1;
	}
	
	// cities exist :) Make sure they're connceted
	// if there is no road give an error message
	if (!checkEdge(city1, city2))
	{
		cout << "Ther is no road between " << city1 << " and " << city2 << endl;
		return 1;
	}

	// search for city 2 in city 1 connections and delete it
	for ( listIterator =map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
		if (listIterator->first == city2)
		{
			map[city1].erase(listIterator);
			break;
		}
		
	// search for city 1 in city 2 connections and delete it
	for ( listIterator = map.at(city2).begin(); listIterator != map.at(city2).end(); listIterator++)
		if (listIterator->first == city1) 
		{
			map[city2].erase(listIterator);
			break;
		}

	return 0;
}

void graph::display()
{
	cout << "\n The elements in this Graph are: \n";
	//display the key value once
	for (mapIterator = map.begin(); mapIterator != map.end(); mapIterator++)
	{
		// itr works as a pointer to 
		// itr->first stores the key part and
		// itr->second stores the value part

		cout << "City: " << mapIterator->first << endl;
		cout << "Adjacent cities are: " << endl;


		//display the linked list compmnents "the value of the map's key"
		for (listIterator = mapIterator->second.begin(); listIterator != mapIterator->second.end(); ++listIterator)
		{
			cout << (*listIterator).first << " ( Distance =  " << (*listIterator).second << " )" << endl;
		}
		cout << "\t\t\t=======================================================================" << endl;
	}
}


//DINA AND MAYAR
/**
* getAdj - gives the adjacency list of the given node
* @city: the city to get its adjaceny list
* @adj: a list that to point to the desired list
*
* Return: nothing
*/
void graph::getAdjacentList(string city, list<pair <string, float>>& adj) {
	mapIterator = map.find(city);
	adj = mapIterator->second;
}

/**
 * Checks if a city with the given name exists in the graph.
 *
 * @param cityName The name of the city to check.
 * @return True if a city with the given name exists in the graph, false otherwise.
 */
bool graph::checkCity(string cityName) {
	for (mapIterator = map.begin(); mapIterator != map.end(); mapIterator++) {
		if (cityName == mapIterator->first) {
			return true;
		}
	}
	return false;
}

/**
 * Checks if an edge between two cities with the given names exists in the graph.
 *
 * @param city1 The name of the first city.
 * @param city2 The name of the second city.
 * @return True if an edge between the two cities exists in the graph, false otherwise.
 */
bool graph::checkEdge(string city1, string city2) {
   list<pair <string, float>> adjacent;
   getAdjacentList(city1, adjacent);
   for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++) {
	   if (city2 == listIterator->first)
		   return true;
   }
   return false;
}

graph :: ~graph()
{
	map.clear();
}