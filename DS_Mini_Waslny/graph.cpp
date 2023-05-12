#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include <list>
#include "graph.h"
#include <fstream>

using namespace std;

/*
	* Notes:
	* map.at() -> returns a pointer to the value
	* map.insert() -> adds a new key-value
	* map.find() -> return an iterator pointing to bucket value (the vertex in our case)
	*				if it exists and to the last vertex if it doesn't
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
	ad=getOutAdjacent(city1);
		for (auto& x:ad)
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
		adjacentList=getOutAdjacent(city1);
		for (auto& x : adjacentList)
		{
			if (city2 == x.first)
			{
				x.second = distance;
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

	list<pair<string, float>> adjacents;
	
	// delete connections with its out-adjacents
	adjacents=getOutAdjacent(cityName);
	for (auto& listPair : adjacents)
		deleteRoad(cityName, listPair.first);

	// delete connections with its in-adjacents
	adjacents=getInAdjacents(cityName);
	for (auto& listPair : adjacents)
		deleteRoad(listPair.first, cityName);

	// remove city 
	map.erase(cityName);
	vertexNum--;
	*/

	list<pair <string, float>> adjacents;

	//delete "out connections" of parameter city
	getOutAdjacent(cityName,adjacents);
	for (listIterator = adjacents.begin(); listIterator != adjacents.end(); listIterator++)
			map[cityName].erase(listIterator);
	adjacents.clear();

	//delete "in connections" of parameter city

	
	
	
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
		// delete city2 from the adjacent list of city1
		deleteEdge(city1, city2);
	}
	// one way road from city2 to city1
	else if (checkEdge(city2, city1) && !checkEdge(city1, city2))
	{
		// delete city1 from the adjacent list of city2
		deleteEdge(city2, city1);
	}
	// 2 way road
	else if (checkEdge(city1, city2) && checkEdge(city2, city1))
	{
		// with the same distance
		if (getEdgeWieght(city1, city2) == getEdgeWieght(city2, city1))
		{
			// delete city2 from the adjacent list of city1 
		    // AND delete city1 from the adjacent list of city2
			deleteEdge(city1, city2);
			deleteEdge(city2, city1);
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
				deleteEdge(city1, city2);
			else if (choice == 2)
				deleteEdge(city2, city1);
			else
			{
				deleteEdge(city1, city2);
				deleteEdge(city2, city1);
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

void graph::deleteEdge(string city1,string city2) 
{
	list <pair <string, float>>::iterator listIterator;
	for (listIterator = map.at(city1).begin(); listIterator != map.at(city1).end(); listIterator++)
		if (listIterator->first == city2)
		{
			map[city1].erase(listIterator);
			break;
		}
}


/**
* displays the adjacency list of all the nodes in the graph
* 
* @return nothing
*/
void graph::display()
{
	cout << "\n\tThe elements in this Graph are: \n";
	//display the key value once
	for (auto& bucket : map)
	{
		cout << "City: " << bucket.first << endl;

		for (auto& listPair : bucket.second)
			cout <<'\t' << listPair.first << " ( Distance =  " << listPair.second << " )" << endl;

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
list<pair <string, float>> graph::getOutAdjacent(string city) {
	unordered_map <string, list<pair <string, float>>>::iterator mapIterator;

	mapIterator = map.find(city);
	return mapIterator->second;
}

/**
* fills the given list with the in-adjacent vertices.
* 
* @param city the city to get its in-adjacents
* @param myList a list to fill in with in-adjacents
* @return nothing
*/
list<pair <string, float>> graph::getInAdjacents(string city)
{
	list<pair <string, float>> myList;
	float backDistance;
	for (auto& bucket : map)
	{
		// if you find a road from any city to the city we're getting its in-adjacents
		if (checkEdge(bucket.first, city))
		{
			// get the distance from that city to to city we're getting its in-adjacents
			for (auto& listPair : bucket.second)
				if (listPair.first == city)
					backDistance = listPair.second;

			// add the founded city with its distance to the adjaceny list we're filling
			myList.push_back(make_pair(bucket.first, backDistance));
		}
	}
	return myList;
}

/**
* getAdjacentVertices - puts all the adjacent vertices (in & out) in the provided list
* @city: the city to get its adjacents
* @adj: the list to fill with the adjacents
*
* note: the list will have duplicates if there were 2 edges with the same weight between
* the given city and any other city
*
* Return: nothing
*/
list<pair<string, float>> graph::getAdjacentVertices(string city)
{
	list<pair<string, float>> adjOut, adjIn;

	// Fill it with the out-adjacents in the list
	adjOut = getOutAdjacent(city);

	// Put the in-adjacents in the list
	adjIn = getInAdjacents(city);

	// Check if each in-adjacent is already in the out-adjacent list
	for (const auto& x : adjIn)
	{
		bool cityExist = false;
		for (const auto& y : adjOut)
		{
			// If the value already exists (like undirected), don't add it to the list
			if (x.first == y.first && x.second == y.second)
			{
				cityExist = true;
				break;
			}
		}
		if (!cityExist)
			adjOut.push_back(make_pair(x.first, x.second));
	}

	return adjOut;
}


/**
 * checkCity - Checks if there is a city with the provided name or not.
 * @cityName: The name of the city to check
 * 
 * Return: True if a city with the given name exists, false otherwise.
 */
bool graph::checkCity(string city)
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
bool graph::checkEdge(string city1, string city2)
{
	if (!checkCity(city1))
		return false;

	if (!checkCity(city2))
		return false;

	// cities exist :)

	list<pair <string, float>> adjacents;
	adjacents=getOutAdjacent(city1);
	for (auto& listPair : adjacents)
		if (listPair.first == city2)
			return true;

	return false;
}

/**
 * Gets distance From City1 To City2 (notice the direction)
 *
 * @param city1 The name of the first city.
 * @param city2 The name of the second city.
 * @return distance if an edge between the two cities exists in the graph, -1 otherwise.
 */
float graph::getEdgeWieght(string city1, string city2)
{
	list<pair <string, float>> adjacents;
	adjacents=getOutAdjacent(city1);
	for (auto& listPair : adjacents)
		if (listPair.first == city2)
			return listPair.second;

	return -1;
}

graph :: ~graph()
{
	for (auto& bucket : map)
		bucket.second.clear();

	map.clear();
}
