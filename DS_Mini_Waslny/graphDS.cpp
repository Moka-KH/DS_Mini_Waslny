#include <iostream>
#include "graphDS.h"
#include <string.h>
#include <utility>  // for pairs
#include <unordered_map>
#include <list>

using namespace std;


/*
	* Notes:
	* map.at() -> return a pointer to the value
	* map.insert() -> adds a new key-value
	* map.find() -> return an iterator pointing to the vertex if it exists
	*				and to the last vertex if it doesn't
	* map.erase() -> return 1 if found key and erase it otherwise return 0
	*/

graphDS::graphDS()
{
	vertexNum = 0;
}

void graphDS::incrementVertexNum()
{
	vertexNum++;
}

void graphDS::decrementVertexNum()
{
	vertexNum--;
}

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
		map.insert(make_pair(newCity, newList));

		//increment number of cities
		incrementVertexNum();

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

	// if it already exists
	if (mapIterator != map.end())
		cout << "City " << newCity << "already exists =| \n";
	else //add the new city
	{
		//empty list
		list <pair <string, int>> newList;
		//make new list for the new city
		map.insert(make_pair(newCity, newList));
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
	// if at least of the cities don't exist
	if (map.find(city1) == map.end() ||
		map.find(city2) == map.end())
	{
		cout << "At least one of the cities you entered doesn't exist :(\n"
			<< "Make sure you wrote the names right / Add the cities first";
		return;
	}

	// ===  add the road  ===

	// keep the city to be connected to & distance in a pair holder
	pairHolder.first = city2;
	pairHolder.second = distance;

	// then add this pair holder to the linked list
	map.at(city1).push_back(pairHolder);
}

/**
* deleteCity - Deletes a City
* @cityName: City Name to be deleted
*
* Description: if the city already exists, it gives an Error Message
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
		cout << "The city you have entered does not exists :(\n"
			<< "Make sure you wrote the name right\n";
	}

	// decrement number of cities
	decrementVertexNum();
}

void graphDS::display()
{
	cout << "\nElements : \n";
	for (mapIterator = map.begin(); mapIterator != map.end(); mapIterator++) //display the key value once
	{
		// itr works as a pointer to 
		// itr->first stores the key part and
		// itr->second stores the value part

		cout << mapIterator->first << endl;

		for (itrList = mapIterator->second.begin(); itrList != mapIterator->second.end(); ++itrList) //display the linked list compmnents "the value of the map's key"
		{
			cout << (*itrList).first << "  " << (*itrList).second << endl;
		}
		cout << "\t\t\t=====================================" << endl;
	}
}

graphDS :: ~graphDS()
{
	map.clear();

}