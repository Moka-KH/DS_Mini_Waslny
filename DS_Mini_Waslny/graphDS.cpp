#include "graphDS.h"
#include <iostream>
#include <string.h>
#include <utility>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void graphDS::addCity(string newCity)
{
	//itrator pointing to the vertex if exists or to the last one if it doesn't
	itrMap = map.find(newCity);

	if (itrMap != map.end())
	{
		cout << "City already exists =| \n";
	}
	//adding new city
	else
	{
		//empty list
		list <pair <string, int>> newList;

		//make new list for the new city
		map.insert(make_pair(newCity, newList));

	}
}

void graphDS::addCity(string newCity, string adjCity, int distance)
{
	//values of list 
	listPair.first = adjCity;
	listPair.second = distance;

	//itrator pointing to the vertex if exists or to the last one if it doesn't
	itrMap = map.find(newCity);

	if (itrMap != map.end())
	{
		cout << "City already exists =| \n";
	}
	//adding new city
	else
	{
		//empty list
		list <pair <string, int>> newList;
		//make new list for the new city
		map.insert(make_pair(newCity, newList));
		addEdge(newCity, adjCity, distance);

	}

}


void graphDS::addEdge(string newCity, string adjCity, int distance)
{

	listPair.first = adjCity;
	listPair.second = distance;

	itrMap = map.find(newCity);

	if (itrMap != map.end())
	{
		cout << "City already exists =| \n";
	}
	//adding new city
	else
	{
		//empty list
		list <pair <string, int>> newList;
		//make new list for the new city
		map.insert(make_pair(newCity, newList));
		addEdge(newCity, adjCity, distance);

	}

	//if (itrMap != map.end()) //Element is Present
	//{
	//	map.at(newCity).push_back(Pgraph); //update the linked list

	//}
	//else //Element is Not Present
	//{
	//	list <pair <string, int>> newList;

	//	newList.push_back(Pgraph); //or front

	//	map.insert(make_pair(newCity, newList)); //make new list for the new city
	//}

}



void graphDS::display()
{
	cout << "\nElements : \n";
	for (itrMap = map.begin(); itrMap != map.end(); itrMap++) //display the key value once
	{
		// itr works as a pointer to 
		// itr->first stores the key part and
		// itr->second stores the value part

		cout << itrMap->first << endl;

		for (itrList = itrMap->second.begin(); itrList != itrMap->second.end(); ++itrList) //display the linked list compmnents "the value of the map's key"
		{
			cout << (*itrList).first << "  " << (*itrList).second << endl;
		}
		cout << "\t\t\t=====================================" << endl;
	}
}

graphDS :: ~graphDS()
{
	map.erase(map.begin());

}