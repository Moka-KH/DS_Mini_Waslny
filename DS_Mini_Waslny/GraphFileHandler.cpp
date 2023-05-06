#pragma once
#include <iostream>
#include <string.h>
#include "GraphFileHandler.h"
#include "graph.h"
#include <fstream>
#include <unordered_map>

using namespace std;

void writeGraphToFile(graph& g, const string& filename) {
	ofstream outFile(filename);
	if (!outFile.is_open()) {
		cout << "Unable to open file for writing." << endl;
		return;
	}
	// write the number of vertices in the graph
	outFile << g.getVertexNum() << endl;
	// iterate over each city and its adjacent list
	for (const auto& cityPair : g.map) {
		// write the city name
		outFile << cityPair.first << endl;
		// write the number of adjacent vertices
		outFile << cityPair.second.size() << endl;
		// iterate over each adjacent vertex and its distance
		for (const auto& adjPair : cityPair.second)
		{
			// write the adjacent city name and its distance
			outFile << adjPair.first << " " << adjPair.second << endl;
		}
	}
	outFile.close();
}

void readGraphFromFile(graph& g, const string& filename) {
	ifstream inFile(filename);
	if (!inFile.is_open()) 
	{
		cout << "Unable to open file for reading." << endl;
		return;
	}
	// read the number of vertices in the graph
	int vertexNum; 
	inFile >> vertexNum; 
	g.setVertexNum(vertexNum);
	string cityName, adjCityName;
	float distance;
	// read each city and its adjacent list
	while (inFile >> cityName)
	{
		int adjNum;
		inFile >> adjNum;
		// iterate over each adjacent vertex and its distance
		for (int i = 0; i < adjNum; i++) {
			inFile >> adjCityName >> distance;
			// add the adjacent city and its distance to the map
			g.addCity(cityName, adjCityName, distance);
		}
	}
	inFile.close();
}

// Function to write multiple graphs to files
void writeMultipleGraphs( unordered_map<string, graph>& graphs, string& directory) {
	for (auto& graphPair : graphs) {
		string& graphName = graphPair.first;
		graph& g = graphPair.second;
		string filename = directory + "/" + graphName + ".txt";
		writeGraphToFile(g, filename);
	}
}
// Function to read multiple graphs from files
unordered_map<string, graph> readMultipleGraphs(string& directory) {
	unordered_map<string, graph> graphs;
	ifstream fileList(directory + "/filelist.txt");
	if (!fileList.is_open()) {
		cout << "Unable to open filelist.txt for reading." << endl;
		return graphs;
	}
	string filename;
	while (getline(fileList, filename)) {
		string graphName = filename.substr(0, filename.length() - 4); // Remove ".txt" extension
		string filepath = directory + "/" + filename;
		graph g;
		readGraphFromFile(g, filepath);
		graphs[graphName] = g;
	}
	fileList.close();
	return graphs;
}
