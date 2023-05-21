#include "files.h"

#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include "files.h"
#include "graph.h"

void writeGraphToFile(graph& g, const QString& filename) {
    QFile outFile(filename);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cout << "Unable to open file for writing.";
        return;
    }

    QTextStream outStream(&outFile);

    // Write the number of vertices in the graph
    outStream << QString::number(g.getVertexNum()) << "\n";
    // Iterate over each city and its adjacent list
    for (const QString& city : g.map.keys()) {
        // Write the city name
        outStream << city << "\n";

        // Get the adjacent list for the city
        const QList<QPair<QString, float>>& adjList = g.map.value(city);

        // Write the number of adjacent vertices
        outStream << QString::number(adjList.size()) << "\n";

        // Iterate over each adjacent vertex and its distance
        for (const QPair<QString, float>& adjVertex : adjList) {
            // Write the adjacent city name and its distance
            outStream << adjVertex.first << " " << QString::number(adjVertex.second) << "\n";
        }
    }

    outFile.close();
}





void readGraphFromFile(graph& g, const QString& filename)
{
    QFile inFile(filename);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Unable to open file for reading." << "\n";
        return;
    }

    QTextStream inStream(&inFile);

    int vertexNum;
    inStream >> vertexNum;

    QString cityName, adjCityName;
    float distance;

    // Read all city names
    QVector<QString> cityNames;
    for (int i = 0; i < vertexNum; i++) {
        inStream >> cityName;
        inStream.readLine(); // Ignore remaining line
        cityNames.push_back(cityName);
    }

    // Add all cities to the graph
    for (const QString& city : cityNames) {
        g.addCity(QString::fromStdString(city.toStdString()));
    }

    // Read and add roads for each city
    inFile.seek(0);
    inStream >> vertexNum; // Skip the vertex count
    for (int i = 0; i < vertexNum; i++) {
        inStream >> cityName;
        int adjNum;
        inStream >> adjNum;

        // Iterate over adjacent cities and distances
        for (int j = 0; j < adjNum; j++) {
            inStream >> adjCityName >> distance;
            g.addEditRoad(cityName, adjCityName, distance);
        }

    }

    inFile.close();
}

// Function to write multiple graphs to files
void writeMultipleGraphs(const QMap<QString, graph>& graphs, const QString& directory) {
    QFile fileList(directory + "/filelist.txt");
    if (!fileList.open(QIODevice::WriteOnly)) {
        std::cout << "Unable to open filelist.txt for writing." << "\n";
        return;
    }

    QTextStream outStream(&fileList);
    for (const auto& graphPair : graphs.toStdMap()) {
        const QString& graphName = graphPair.first;
        graph g = graphPair.second;
        const QString filename = directory + "/" + graphName + ".txt";
        writeGraphToFile(g, filename);
        outStream << graphName << ".txt" << "\n"; // Add the graph name to filelist.txt
    }

    fileList.close();
}


QMap<QString, graph> readMultipleGraphs(const QString& directory)
{
    QMap<QString, graph> graphs;
    QFile fileList(directory + "/filelist.txt");
    if (!fileList.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Unable to open filelist.txt for reading." << std::endl;
        return graphs;
    }

    QTextStream inStream(&fileList);

    QString filename;
    while (inStream.readLineInto(&filename)) {
        const QString graphName = filename.left(filename.length() - 4); // Remove ".txt" extension
        const QString filepath = directory + "/" + filename;
        graph g;
        readGraphFromFile(g, filepath);
        graphs[graphName] = g;
    }

    fileList.close();
    return graphs;
}
