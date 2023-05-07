#pragma once
#include <iostream>
#include <string.h>
#include <utility>
#include <unordered_map>
#include <list>
#include "graph.h"
#include<fstream>

using namespace std;


/*
	* Notes:
	* map.at() -> returns a pointer to the value
	* map.insert() -> adds a new key-value
	* map.find() -> return an iterator pointing to the vertex if it exists
	*				and to the last vertex if it doesn't
	* map.erase() -> return 1 if found key and erase it otherwise return 0
*/

// this should be deleted
graph::graph()
{
	vertexNum = 0;
}

/**
* graph - the graph constructor
*
* Description: sets the #vertices to zero
*
* Return: nothing
*/
graph::graph(string name)
{
	vertexNum = 0;
	this->name = name;
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
* getEdges - returns #edges
* Return: integer value -> #edges
*/
int graph::getEdges(string city1)
{
	int counter=0;
	list<pair<string, float>> ad;
	getOutAdjacent(city1, ad);
		for (listIterator = ad.begin();listIterator != ad.end();listIterator++)
		{
			counter++;
		}
	return counter;
}

/**
* setVertexNum - set #vertices
* Return: nothing
*/
void graph::setVertexNum(int noVertx)
{
	vertexNum= noVertx;
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
* addRoad - Connects 2 cities / updates the distancde between them
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

	// if the road already exists , just update the distance
	if (checkEdge(city1, city2))
	{
		list<pair <string, float>> adjacentList;
		getOutAdjacent(city1, adjacentList);
		for (auto& listIterator : adjacentList)
		{
			if (city2 == listIterator.first)
			{
				listIterator.second = distance;
				break;
			}
		}
		//update the adjacency list of city1
		map[city1].clear();
		map[city1] = adjacentList;
		cout << endl;
		cout << "The road is updated successfully" << endl;
	}
	else
	{
		// put city2 in city1 conncections
		pairHolder.first = city2;
		pairHolder.second = distance;
		map.at(city1).push_back(pairHolder);
		cout << "The road is added successfully" << endl;
	}
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
	getOutAdjacent(cityName, adjacent);

	//for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++)
	//{
	//	//deleteRoad(cityName, listIterator->first);
	//	map[cityName].clear();
	//	map[cityName].erase(listIterator);
	//}
	for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++) 
	{
		for (listIterator = map.at(cityName).begin(); listIterator != map.at(cityName).end(); listIterator++)
			map[cityName].erase(listIterator);
	}

	////delete it from the lists of its adjacent cities
	////search for cities connected with paramet city
	for (auto& vertex : map)
	{
		//if you find a back road from any city to the target city 
		if (checkEdge(vertex.first, cityName))
			for (listIterator = map.at(vertex.first).begin(); listIterator != map.at(vertex.first).end(); listIterator++)
				if(listIterator->first == cityName)
					map[vertex.first].erase(listIterator);
			//deleteRoad(vertex.first, cityName);
	}
	
	// remove city 
	map.erase(cityName);
	vertexNum--;

	cout << "City is deleted\n";
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
		cout << city1 << " doesn't exist :| (from delete road)\n";
		return 1;
	}
	if (!checkCity(city2))
	{
		cout << city2 << " doesn't exist :| (from delete road)\n";
		return 1;
	}

	// one way road from city1 to city2
	if (checkEdge(city1, city2) && !checkEdge(city2, city1))
	{
		for (listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
			if (listIterator->first == city2)
			{
				map[city1].erase(listIterator);
				break;
			}
	}
	// one way road from city2 to city1
	else if (checkEdge(city2, city1) && !checkEdge(city1, city2))
	{
		for (listIterator = map.at(city2).begin(); listIterator != map.at(city2).end(); listIterator++)
			if (listIterator->first == city1)
			{
				map[city2].erase(listIterator);
				break;
			}
	}
	// 2 way road
	else if (checkEdge(city1, city2) && checkEdge(city2, city1))
	{
		// with the same distance
		if (getEdgeWieght(city1, city2) == getEdgeWieght(city2, city1))
		{
			for (listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
				if (listIterator->first == city2)
				{
					map[city1].erase(listIterator);
					break;
				}

			for (listIterator = map.at(city2).begin(); listIterator != map.at(city2).end(); listIterator++)
				if (listIterator->first == city1)
				{
					map[city2].erase(listIterator);
					break;
				}
		}
		// with different distances
		else
		{
			int choice;
			cout << "1- delete road from " << city1 << " to " << city2 << "\n"
				<< "2- delete road from " << city2 << " to " << city1 << "\n"
				<< "3- delete  both roads \n";
			cin >> choice;

			if (choice == 1)
			{
				for (listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
					if (listIterator->first == city2)
					{
						map[city1].erase(listIterator);
						break;
					}
			}
			else if (choice == 2)
			{
				for (listIterator = map.at(city2).begin(); listIterator != map.at(city2).end(); listIterator++)
					if (listIterator->first == city1)
					{
						map[city2].erase(listIterator);
						break;
					}
			}
			else
			{
				for (listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
					if (listIterator->first == city2)
					{
						map[city1].erase(listIterator);
						break;
					}

				for (listIterator = map.at(city2).begin(); listIterator != map.at(city2).end(); listIterator++)
					if (listIterator->first == city1)
					{
						map[city2].erase(listIterator);
						break;
					}
			}
		}
	}
	// no road
	else
	{
		cout << "There is no road between " << city1 << " and " << city2 << ":(\n";
		return 1;
	}

	cout << "Road is deleted\n";
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

		//display the linked list compmnents "the value of the map's key"
		for (listIterator = mapIterator->second.begin(); listIterator != mapIterator->second.end(); ++listIterator)
		{
			cout <<'\t' << (*listIterator).first << " ( Distance =  " << (*listIterator).second << " )" << endl;
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
void graph::getOutAdjacent(string city, list<pair <string, float>>& adj) { //getOutAdjacent ####
	mapIterator = map.find(city);
	adj = mapIterator->second;
}

/**
* getAdjacentVertices - gives the adjacency list of the given node
* @city: the city to get its adjaceny list
* @adj: a list that to point to the desired list
*
* Return: nothing
*/
void graph::getAdjacentVertices(string city, list<pair <string, float>>& adjList)
{
	getOutAdjacent(city, adjList); //adjList contains B, I
	float backDistance;
	bool exists = false;

	//search for cities connected with city
	for (auto& vertex : map)
	{
		//if you find a back road from any city to the target city 
		if (checkEdge(vertex.first, city)) //vertex.first => B
		{
			
			// if the city was already in the adjacency list of city mark as exists
			for (auto& listIterator : adjList)
				if (vertex.first == listIterator.first)
					exists = true;

			// make sure it's not already in the list
			if (exists == false)
			{
				for (auto& listIterator : map[vertex.first])
					if (listIterator.first == city)
						backDistance = listIterator.second;

				//add the founded city with its distance to the adjaceny list to be returned
				adjList.push_back(make_pair(vertex.first, backDistance));
			}



		}
	}
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
	if (!checkCity(city1))
		return false;

	if (!checkCity(city2))
		return false;

	// cities exist :)

	list<pair <string, float>> adjacent;
	getOutAdjacent(city1, adjacent);
	for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++)
		if (city2 == listIterator->first)
			return true;

	return false;
}

/**
 * Gets distance between two cities with the given names.
 *
 * @param city1 The name of the first city.
 * @param city2 The name of the second city.
 * @return distance if an edge between the two cities exists in the graph, -1 otherwise.
 */
float graph::getEdgeWieght(string city1, string city2) {
	list<pair <string, float>> adjacent;
	getOutAdjacent(city1, adjacent);
	for (listIterator = adjacent.begin(); listIterator != adjacent.end(); listIterator++) {
		if (city2 == listIterator->first)
			return listIterator->second;
	}
	return -1;
}

graph :: ~graph()
{
	map.clear();
}
