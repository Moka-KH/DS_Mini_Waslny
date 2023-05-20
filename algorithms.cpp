#include "algorithms.h"

#include <QMap>
#include <QHash>
#include <QList>
#include <QStack>
#include <QQueue>
#include <QVector>
#include <QPair>
#include <limits>
#include <vector>
#include <queue>

const float INFINITE = FLT_MAX;

QStack<QPair<QString, float>> backTracking(graph& myGraph, QString startingVertex, QString targetVertex, QHash<QString, QString> previousVerteces)
{
    QStack<QPair<QString, float>> path;
    QString currentVertex = targetVertex;
    QString previousVertex = previousVerteces[currentVertex];
    float distance;

    while (currentVertex != startingVertex)
    {
        // get the distance from previous vertex to the current one
        QList<QPair<QString, float>> inCurrentAdjacent = myGraph.getInAdjacents(currentVertex);
        QMutableListIterator<QPair <QString, float>> listPair(inCurrentAdjacent);
        for ( ;listPair.hasNext();listPair.next())
        {
            if (listPair.value().first == previousVertex)
                distance = listPair.value().second;
        }
        QPair<QString, float> myPair(currentVertex, distance);
        path.push(myPair);

        currentVertex = previousVertex;
        previousVertex = previousVerteces[currentVertex];
    }
    return path;
}

float Dijkstra(graph& myGraph,QString startingNode, QString targetVertex, QStack<QPair<QString, float>>& path)
{
    /*
    this structure is a priority queue using the minimum heap data structure(greater<myPair>)
    (a queue that puts the least element in its front)
    knowing a vertex means updating its adjacents' costs with new better values (if any)
    */
    std::priority_queue<std::pair<float, QString>, std::vector<std::pair<float, QString>>, std::greater<std::pair<float, QString>>> unKnownVertices;


    // stores the shortest found path till now for all the verteces & set all costs to infinity
    QMap<QString,float> cost;
    QMutableHashIterator <QString, QList<QPair <QString, float>>> costbucket(myGraph.map);
    for ( ;costbucket.hasNext();costbucket.next())
    {
        cost.insert(costbucket.key(), INFINITE);
    }
    cost[startingNode] = 0;

    // stores the previous vertex of each vertex (set it all to "" )
    QHash<QString, QString> previousVerteces;
    QMutableHashIterator <QString, QList<QPair <QString, float>>> bucket(myGraph.map);
    for ( ;bucket.hasNext();bucket.next())
    {
        previousVerteces[bucket.key()] = "";
    }

    QPair<float, QString> queuePair(0, startingNode);
    unKnownVertices.push(queuePair);

    // Determine the shortest path for each city
    while (!unKnownVertices.empty())
    {
        // get the name of the city with minimum distance
        QString currentVertexName = unKnownVertices.top().second;
        unKnownVertices.pop();

        QList<QPair <QString, float>> outAdjacents = myGraph.getOutAdjacents(currentVertexName);

        // if taking a path using the current node to one of its adjacents is shorter
        // update it the costs with this value
        QMutableListIterator<QPair <QString, float>> adjacent(outAdjacents);
        for ( ;adjacent.hasNext();adjacent.next())
        {
            QString adjacentName = adjacent.value().first;
            float weight = adjacent.value().second; // from the current vertex to this adjacent

            if (cost[adjacentName] > cost[currentVertexName] + weight)
            {
                // update the cost
                cost[adjacentName] = cost[currentVertexName] + weight;

                // set the preceding vertex
                previousVerteces[adjacentName] = currentVertexName;

                // put this adjacent in the unknown vertices to know it later
                QPair<float, QString> queuePair(cost[adjacentName], adjacentName);
                unKnownVertices.push(queuePair);
            }
        }

    }

    // if there is no path to the target vertex
    if (cost[targetVertex] == INFINITE)
        return -1.0;
    else
    {
        path = backTracking(myGraph, startingNode, targetVertex, previousVerteces);
        return cost[targetVertex];
    }
}

QQueue<QString> DFS(graph& myGraph, QString startVetrex)
{
    QHash<QString, bool> visited;

    // initialize all vertices to be "unvisited" first
    QMutableHashIterator <QString, QList<QPair <QString, float>>> bucket(myGraph.map);
    for ( ;bucket.hasNext();bucket.next())
    {
        visited[bucket.key()]=false;
    }

    QStack<QString> NodesToCheckNeighbors;
    NodesToCheckNeighbors.push(startVetrex);

    // create a queue to store the outputs of the DFS function
    QQueue<QString> DFSQueue;

    //traverse on connected vertices
    while (!NodesToCheckNeighbors.empty())
    {
        // return top vertex and pop it to mark it as "visited"
        QString currentNode = NodesToCheckNeighbors.top();
        NodesToCheckNeighbors.pop();

        if (!visited[currentNode])
        {
            // print & mark the current vertex as "visited"
            DFSQueue.enqueue(currentNode);
            visited[currentNode] = true;

            // get the adjacency list of the current vertex
            QList<QPair<QString, float>> adjacencyList;
            adjacencyList = myGraph.getAdjacents(currentNode);

            // iterate over the adjacent vertices of current node
            QMutableListIterator<QPair <QString, float>> it(adjacencyList);
            for ( ;it.hasNext();it.next())
            {
                // push the non-visited adjacents into the stack
                if (!visited[it.value().first])
                    NodesToCheckNeighbors.push(it.value().first);
            }
        }
    }

    //traverse on isolated vertices
    QMutableHashIterator <QString, QList<QPair <QString, float>>> mapIterator(myGraph.map);
    for ( ;mapIterator.hasNext();mapIterator.next())
    {
        if (visited[mapIterator.key()] == false)
            DFSQueue.enqueue(mapIterator.key());
    }
    return DFSQueue;
}
