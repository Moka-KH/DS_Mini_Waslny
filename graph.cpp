#include "graph.h"

graph::graph()
{
    vertexNum = 0;
    edgeNum = 0;
}

int graph::getVertexNum()
{
    return vertexNum;
}

QList<QPair<QString, float>> graph::getOutAdjacents(QString city)
{
    return map[city];
}

QList<QPair<QString, float>> graph::getInAdjacents(QString city)
{
    QList<QPair<QString, float>> adjacents;
    float backDistance;
    QMutableHashIterator <QString, QList<QPair <QString, float>>> bucket(map);
    while(bucket.hasNext())
    {
        // if you find a road from any city to the city we're getting its in-adjacents
        if (edgeExists(bucket.key(), city))
        {
            // get the distance from that city to to city we're getting its in-adjacents
            QMutableListIterator<QPair<QString, float>> listPair(bucket.value());
            while(listPair.hasNext())
            {
                if (listPair.value().first == city)
                {
                    backDistance = listPair.value().second;
                }
                listPair.next();
            }
            // add the founded city with its distance to the adjaceny list we're filling
            QPair<QString, float> myPair(bucket.key(),backDistance);
            adjacents.push_back(myPair);
        }
        bucket.next();
    }
    return adjacents;
}

bool graph::vertexExists(QString city)
{
    return map.contains(city);
}

bool graph::edgeExists(QString city1, QString city2)
{
    if (!vertexExists(city1) || !vertexExists(city2))
        return false;

    QList<QPair <QString, float>> adjacents;
    adjacents = getOutAdjacents(city1);
    QMutableListIterator<QPair <QString, float>> listPair(adjacents);
    while(listPair.hasNext())
    {
        if(listPair.value().first==city2)
            return true;
        listPair.next();
    }
    return false;
}

int graph::addCity(QString city)
{
    if (vertexExists(city))
        return cityExists;

    QList <QPair <QString, float>> newList;
    map[city] = newList;
    vertexNum++;

    return success;
}
