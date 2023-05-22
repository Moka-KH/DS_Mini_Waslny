#include "graph.h"
#include "enumerators.cpp"
#include <QString>

// constructors & destructor
graph::graph()
{
    vertexNum = 0;
    edgeNum = 0;
}
graph::graph(QString name)
{
    this->name = name;
    vertexNum = 0;
    edgeNum = 0;
}
graph::~graph()
{
    QMutableHashIterator<QString, QList<QPair<QString, float>>> bucket(map);
    for (; bucket.hasNext(); bucket.next())
        bucket.value().clear();
    map.clear();
}

// Getters
int graph::getVertexNum()
{
    return vertexNum;
}
int graph::getEdgeNum()
{
    return edgeNum;
}
int graph::getOutEdgesNumber(QString city1)
{
    int counter = 0;
    QList<QPair<QString, float>> adjacents = getOutAdjacents(city1);
    QMutableListIterator<QPair<QString, float>> listPair(adjacents);

    for (;listPair.hasNext();listPair.next())
        counter++;
    return counter;
}
float graph::getEdgeWeight(QString city1, QString city2)
{
    QList<QPair<QString, float>> adjacents = getOutAdjacents(city1);
    QMutableListIterator <QPair<QString, float>> listPair(adjacents);
    for (; listPair.hasNext();listPair.next())
    {
        if(listPair.value().first == city2)
            return listPair.value().second;
    }
    return -1;
}

QList<QPair<QString, float>> graph::getOutAdjacents(QString city)
{
    return map[city];
}
QList<QPair<QString, float>> graph::getInAdjacents(QString city)
{
    QList<QPair<QString, float>> adjacents;
    QMutableHashIterator <QString, QList<QPair <QString, float>>> bucket(map);
    float backDistance;

    for(;bucket.hasNext();bucket.next())
    {
        // if you find a road from any city to the city we're getting its in-adjacents
        if (edgeExists(bucket.key(), city))
        {
            // get the distance from that city to to city we're getting its in-adjacents
            QMutableListIterator <QPair<QString, float>> listPair(bucket.value());
            for(;listPair.hasNext();listPair.next())
            {
                if (listPair.value().first == city)
                    backDistance = listPair.value().second;
            }
            // add the founded city with its distance to the adjaceny list we're filling
            QPair <QString, float> myPair (bucket.key(),backDistance);
            adjacents.push_back(myPair);
        }
    }
    return adjacents;
}
QList<QPair<QString, float>> graph::getAdjacents(QString city)
{
    // get in IN & OUT in 2 separate lists
    QList<QPair<QString, float>> outAdjacents, inAdjacents;
    outAdjacents = getOutAdjacents(city);
    inAdjacents = getInAdjacents(city);

    // combine them in the inAdjacents list and don't take the duplicates
    // for each element in the INs
    QMutableListIterator<QPair<QString, float>> in(inAdjacents);
    for (; in.hasNext(); in.next())
    {
        // iterate over the OUTs
        QMutableListIterator<QPair<QString, float>> out(inAdjacents);
        for (; out.hasNext(); out.next())
        {
            // if you find a repeated value, don't take it into the INs..
            // continue to the next OUT
            if (in.value().first == out.value().first && in.value().second == out.value().second)
                break;

            // non-repeated value
            QPair<QString, float> newPair(out.value().first, out.value().second);
            inAdjacents.push_back(newPair);
        }
    }

    return inAdjacents;
}

// Boolean Checkers
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
    for (; listPair.hasNext();listPair.next())
    {
        if(listPair.value().first == city2)
            return true;
    }
    return false;
}
bool graph::empty()
{
    return (map.empty() ? true : false);
}

// Roads
int graph::addEditRoad(QString city1, QString city2, float distance)
{
    // if the road already exists, just update the distance
    if (edgeExists(city1, city2))
    {
        QMutableListIterator<QPair<QString, float>> listPair(map[city1]);
        for (; listPair.hasNext(); listPair.next())
        {
            if (city2 == listPair.value().first)
            {
                listPair.value().second = distance;
                break;
            }
        }

        return updatedRoad;
    }

    // no road between them.. add it
    QPair<QString, float> newPair(city2, distance);
    map[city1].push_back(newPair);
    return addedRoad;
}
void graph::deleteEdge(QString city1,QString city2)
{
    // the method removeOne() removes the first element in the container
    // with the value provided
    QPair<QString, float> myPair(city2, getEdgeWeight(city1, city2));
    map[city1].removeOne(myPair);

    /*
    QListIterator<QPair<QString, float>> listPair(map[city1]);
    for (; listPair.hasNext(); listPair.next())
    {
        if (listPair.value().first == city2)
        {
            map[city1].erase(listPair);
            break;
        }
    }
    */
}

//Cities
int graph:: deleteCity(QString cityName)
{
    QList<QPair<QString, float>> adjacents;
    // delete connections with its out-adjacents
    adjacents = getOutAdjacents(cityName);
    QMutableListIterator <QPair<QString, float>> listPair(adjacents);
    for (; listPair.hasNext();listPair.next())
    {
        if(edgeExists(cityName, listPair.value().first) && edgeExists(listPair.value().first, cityName))
        {
            // delete city2 from the adjacency list of city1
            // AND delete city1 from the adjacency list of city2
            deleteEdge(cityName, listPair.value().first);
            deleteEdge(listPair.value().first, cityName);
        }
        else
            deleteEdge(listPair.value().first, cityName);
    }

    // delete connections with its in-adjacents
    adjacents=getInAdjacents(cityName);
    for (; listPair.hasNext();listPair.next())
        deleteEdge(listPair.value().first, cityName);

    // remove city
    map.remove(cityName);
    vertexNum--;

    return Cdeleted;
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

// Others
QString  graph:: display()
{
    QMutableHashIterator <QString , QList<QPair<QString, float>>> bucket(map);
    QString displayString;

    for(;bucket.hasNext();bucket.next())
    {
        displayString.append("\nCity: "+ bucket.key() + "\n");

        QMutableListIterator <QPair<QString, float>> listPair(bucket.value());
        for(;listPair.hasNext();listPair.next())
        {
            QString distance = QString::number(listPair.value().second);
            displayString.append("\t" + listPair.value().first + " ( Distance =  " + distance + "\n");
        }
        displayString.append("\t\t\t=======================================================================\n");
    }
    return displayString;
}
