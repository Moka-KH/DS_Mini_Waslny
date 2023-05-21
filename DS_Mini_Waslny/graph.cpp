#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <list>
#include <fstream>
#include "graph.h"
#include "enumerators.cpp"

using namespace std;

/*
	* Notes:
	* map.at() -> returns a pointer to the value
	* map.insert() -> adds a new key-value
	* map.find() -> return an iterator pointing to bucket value (the vertex in our case)
	*				if it exists and to the last vertex if it doesn't
	* map.erase() -> return 1 if found key and erase it otherwise return 0
*/

graph::graph()
{
	vertexNum = 0;
	edgeNum = 0;
}
graph::graph(string name)
{
	graph();
	this->name = name;
}
graph :: ~graph()
{
	for (auto& bucket : map)
		bucket.second.clear();

	map.clear();
}

/**
* emptyGraph - check if graph empty or not
* Return: boolean value -> true if empty false if not empty
*/
bool graph::empty()
{
	if (map.empty())
		return true;
	return false;
}

/**
* getVertexNum - returns #vertices
* Return: integer value -> #vertices
*/
int graph::getVertexNum()
{
	return vertexNum;
}
int graph::getEdgeNum()
{
	return edgeNum;
}

/**
* displays the adjacency list of all the nodes in the graph
*
* @return void
*/
void graph::display()
{
	if (map.empty())
	{
		cout << "You don't have any cities in this map yet!" << endl;
		return;
	}

	cout << "\n\tMap Cities:\n";
	for (auto& bucket : map)
	{
		cout << "City: " << bucket.first << endl;

		for (auto& listPair : bucket.second)
			cout << '\t' << listPair.first << " ( Distance =  " << listPair.second << " )" << endl;

		cout << "\t\t\t=======================================================================" << endl;
	}
}

///

/**
* @brief Adds a new City
* 
*
* it exits with an ineteger representing an error if the city already exists
* otherwise, it adds a vertex and its list in the map
* 
* @city City Name
* @return returns an addCity_enum according to the ending state (success / failure)
*/
int graph::addCity(string city)
{
	if (vertexExists(city))
		return cityExists;

	list <pair <string, float>> newList;
	map[city] = newList;
	vertexNum++;

	return success;
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
	// I didn't handle messages of this function yet.. I think we'll remove it
	// if the vetex to be added already exists
	if (vertexExists(newCity))
	{
		cout << "City " << newCity << " already exists =| \n";
		return cityExists;
	}

	// if the vertex we'are connecting to doesn't exist
	if (!vertexExists(adjCity))
	{
		cout << "City " << adjCity << " doesn't exist. You can't link to it\n";
		return noCity2;
	}

	// reaching here means the input is valid

	// add the new city and give it a list as a value in the map
	list <pair <string, float>> newList;
	map[newCity] = newList;

	// link it with city2
	addEditRoad(newCity, adjCity, distance);
	return 0;
}

/**
* This function connects adds / updates the distancde between 2 cities
* 
*
* Description: makes sure both of them exist.
*			   if so, adds the road
* @param city1 first city
* @param city2 second city
* @param distance Distance
* @return returns a addRoad_enum according to the ending state
*/
int graph::addEditRoad(string city1, string city2, float distance)
{
	// if the first one doesn't exist
	if (!vertexExists(city1))
		return noCity1;

	// if the second one doesnt exist
	if (!vertexExists(city2))
		return noCity2;

	// if the road already exists , just update the distance
	if (edgeExists(city1, city2))
	{
		for (auto& x : map.at(city1))
		{
			if (city2 == x.first)
			{
				x.second = distance;
				break;
			}
		}
		return updatedRoad;
	}

	// no road between them.. add it
	map.at(city1).push_back(make_pair(city2, distance));
	return addedRoad;
}

///

/**
* @brief Deletes a City
* 
* if the city doesn't exist, it gives an Error Message
* else it removes the list of adjacent vertices
* and finally removes the node itself
* 
* @cityName: City Name to be deleted
* @return void
*/
void graph::deleteCity(string cityName) //note from Malk -> still working on the messages that appears to user =| 
{
	if (!vertexExists(cityName))
	{
		cout << "city " << cityName << " does not exist.. I can't delete it =(\n";
		return;
	}

	list<pair<string, float>> adjacents;
	
	// delete connections with its out-adjacents
	adjacents=getOutAdjacents(cityName);
	for (auto& listPair : adjacents)
	{
		if (edgeExists(cityName, listPair.first) && edgeExists(listPair.first, cityName))
		{
			if (EdgeWieght(cityName, listPair.first) != EdgeWieght(listPair.first, cityName))
			{
				// delete city2 from the adjacency list of city1 
				// AND delete city1 from the adjacency list of city2
				deleteEdge(cityName, listPair.first);
				deleteEdge(listPair.first, cityName);
			}
			else
				deleteRoad(listPair.first, cityName);
		}
		else
			deleteRoad(listPair.first, cityName);

	}

	// delete connections with its in-adjacents
	adjacents=getInAdjacents(cityName);
	for (auto& listPair : adjacents)
			deleteRoad(listPair.first, cityName);

	// remove city
	map.erase(cityName);
	vertexNum--;

	cout << "City is deleted\n";
	return;
}

/**
* @brief This function deletes a road between 2 cities
* 
*
* first makes sure that cities exist. if so, it makes sure they're conncected.
* if so, it deletes the connection depending on its type (one way or roundway)
*
* @param city1 first city
* @param city2 second city
* @return void
*/
void graph::deleteRoad(string city1, string city2)
{
	// if at least one city doesn't exist
	if (!vertexExists(city1))
	{
		cout << '\"' << city1 << "\" doesn't exist =|\n";
		return;
	}
	if (!vertexExists(city2))
	{
		cout << '\"' << city2 << "\" doesn't exist =|\n";
		return;
	}

	// no road
	if(!edgeExists(city1, city2))
	{
		cout << "There is no road between " << city1 << " and " << city2 << " =(\n";
		return;
	}
	// one way road from city1 to city2
	else if (edgeExists(city1, city2) && !edgeExists(city2, city1))
		// delete city2 from the adjacency list of city1
		deleteEdge(city1, city2);
	
	// one way road from city2 to city1
	else if (edgeExists(city2, city1) && !edgeExists(city1, city2))
		// delete city1 from the adjacency list of city2
		deleteEdge(city2, city1);
	
	// 2 way road
	else if (edgeExists(city1, city2) && edgeExists(city2, city1))
	{
		// with the same distance
		if (EdgeWieght(city1, city2) == EdgeWieght(city2, city1))
		{
			// delete city2 from the adjacency list of city1 
		    // AND delete city1 from the adjacency list of city2
			deleteEdge(city1, city2);
			deleteEdge(city2, city1);
		}
		// with different distances
		else
		{
			int choice;
			while (true)
			{
				cout << "1- delete road from " << city1 << " to " << city2 << "\n"
					<< "2- delete road from " << city2 << " to " << city1 << "\n"
					<< "3- delete  both roads \n";
				cin >> choice;

				if (choice == 1)
					deleteEdge(city1, city2);
				else if (choice == 2)
					deleteEdge(city2, city1);
				else if (choice == 3)
				{
					deleteEdge(city1, city2);
					deleteEdge(city2, city1);
				}
				else
				{
					cout << "Invalid choice!  Try agian\n";
					continue;
				}
				break;
			}
		}
	}
	
	cout << "Road is deleted\n";
	return;
}

void graph::deleteEdge(string city1,string city2) 
{
	for (auto listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
	{
		if (listIterator->first == city2)
		{
			listIterator = map.at(city1).erase(listIterator);
			break;
		}
	}
}

///

/**
* returns the adjacency list of the given vertex
* 
* @city: the city to get its adjaceny list
* @adj: a list that to point to the desired list
* @return the adjacency list
*/
list<pair <string, float>> graph::getOutAdjacents(string city)
{
	return map.at(city);
}

/**
* returns a list filled with the in-adjacents of the given vertex.
* 
* @param city the city to get its in-adjacents
* @return 
*/
list<pair <string, float>> graph::getInAdjacents(string city)
{
	list<pair <string, float>> adjacents;
	float backDistance;
	for (auto& bucket : map)
	{
		// if you find a road from any city to the city we're getting its in-adjacents
		if (edgeExists(bucket.first, city))
		{
			// get the distance from that city to to city we're getting its in-adjacents
			for (auto& listPair : bucket.second)
				if (listPair.first == city)
					backDistance = listPair.second;

			// add the founded city with its distance to the adjaceny list we're filling
			adjacents.push_back(make_pair(bucket.first, backDistance));
		}
	}
	return adjacents;
}

/**
* returns a list of all the adjacent vertices (in & out) of the given vertex
*
* @param city the city to get its adjacents
* Return: a list filled with the adjacents
*/
list<pair <string, float>> graph::getAdjacents(string city) // to be refactored
{
	list<pair <string, float>> outAdjacents, inAdjacents;

	// put the out-adjacents in a list
	outAdjacents = getOutAdjacents(city);

	// put the in-adjacents in a list
	inAdjacents = getInAdjacents(city);

	// combine them into inAdjacents and don't take the duplicates
	for (auto& x : inAdjacents)
	{
		for (auto y : outAdjacents)
		{
			// if you find a repeated value, don't take it.. continue to the next one
			if (x.first == y.first && x.second == y.second)
				break;
			// non-repeated value
			else 
				inAdjacents.push_back(make_pair(y.first, y.second));
		}
	}

	outAdjacents.clear();
	return inAdjacents;
}

/**
* get the number of out-edges of the given vertex
* 
* @param city1 city name
* @return integer value (#edges)
*/
int graph::outEdgesNumber(string city1)
{
	int counter = 0;
	list<pair<string, float>> adjacents = getOutAdjacents(city1);

	for (auto& x : adjacents)
		counter++;
	return counter;
}

/**
 * Checks if there is a city with the provided name or not
 * 
 * @cityName: The name of the city to check
 * @return True if a city with the given name exists, false otherwise.
 */
bool graph::vertexExists(string city)
{
	for (auto& bucket : map)
		if (city == bucket.first)
			return true;

	return false;
}

/**
 * Checks if there is an edge going from city1 to city2
 *
 * @param city1 the first city name
 * @param city2 the secondcity name
 * @return True if an edge between the two cities exists in the graph, false otherwise.
 */
bool graph::edgeExists(string city1, string city2)
{
	if (!vertexExists(city1) || !vertexExists(city2))
		return false;

	list<pair <string, float>> adjacents;
	adjacents = getOutAdjacents(city1);
	for (auto& listPair : adjacents)
		if (listPair.first == city2)
			return true;

	return false;
}

/**
 * Gets distance From City1 To City2 (directional)
 *
 * @param city1 The first city.
 * @param city2 The second city.
 * @return distance if an edge between the two cities exists in the graph, -1 otherwise.
 */
float graph::EdgeWieght(string city1, string city2)
{
	list<pair <string, float>> adjacents = getOutAdjacents(city1);
	for (auto& listPair : adjacents)
		if (listPair.first == city2)
			return listPair.second;

	return -1;
}
