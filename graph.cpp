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

//contains auto !!
QList<QPair<QString, float>> graph::getAdjacents(QString city)
{
    // get in IN & OUT in 2 separate lists
    QList<QPair<QString, float>> outAdjacents, inAdjacents;
    outAdjacents = getOutAdjacents(city);
    inAdjacents = getInAdjacents(city);

    // combine them in the inAdjacents list and don't take the duplicates
    // for each element in the INs
    for (auto& in : inAdjacents)
    {
        // iterate over the OUTs
        for (auto out : outAdjacents)
        {
            // if you find a repeated value, don't take it into the INs..
            // continue to the next OUT
            if (in.first == out.first && in.second == out.second)
                continue;

            // non-repeated value
            QPair<QString, float> newPair(out.first, out.second);
            inAdjacents.push_back(newPair);
        }
    }

    return inAdjacents;
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
    for (; listPair.hasNext();listPair.next())
    {
        if(listPair.value().first == city2)
            return true;
    }
    return false;
}


float graph:: EdgeWieght(QString city1, QString city2)
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

bool graph::emptyGraph()
{
    if (map.empty())
        return true;
    return false;
}

int graph::outEdgesNumber(QString city1)
{
    int counter = 0;
    QList<QPair<QString, float>> adjacents = getOutAdjacents(city1);
    QMutableListIterator<QPair<QString, float>> listPair(adjacents);

    for (;listPair.hasNext();listPair.next())
        counter++;
    return counter;
}

// Roads
int graph::addEditRoad(QString city1, QString city2, float distance)
{
    // if the first city doesn't exist
    if (!vertexExists(city1))
        return noCity1;

    // if the second city doesnt exist
    if (!vertexExists(city2))
        return noCity2;

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

//Cities
void graph:: deleteCity(QString cityName)
{
    if (!vertexExists(cityName))
    {
        qDebug() << "city " << cityName << " does not exist.. I can't delete it =(\n";
        return;
    }

    QList<QPair<QString, float>> adjacents;
    // delete connections with its out-adjacents
    adjacents = getOutAdjacents(cityName);
    QMutableListIterator <QPair<QString, float>> listPair(adjacents);
    for (; listPair.hasNext();listPair.next())
    {
        if(edgeExists(cityName, listPair.value().first) && edgeExists(listPair.value().first, cityName))
        {
            if(EdgeWieght(cityName, listPair.value().first) != EdgeWieght(listPair.value().first, cityName))
            {
                // delete city2 from the adjacency list of city1
                // AND delete city1 from the adjacency list of city2
                deleteEdge(cityName, listPair.value().first);
                deleteEdge(listPair.value().first, cityName);
            }
            else
                deleteRoad(listPair.value().first, cityName);
        }
        else
            deleteRoad(listPair.value().first, cityName);
    }

    // delete connections with its in-adjacents
    adjacents=getInAdjacents(cityName);
    for (; listPair.hasNext();listPair.next())
        deleteRoad(listPair.value().first, cityName);

    // remove city
    map.remove(cityName); //=/
    vertexNum--;

    qDebug() << "City is deleted\n";
    return;
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

void graph:: display()
{
    qDebug() << "\n\tMap Cities:";
    QMutableHashIterator <QString , QList<QPair<QString, float>>> bucket(map);

    for(;bucket.hasNext();bucket.next())
    {
        qDebug() << "\nCity: " << bucket.key();

        QMutableListIterator <QPair<QString, float>> listPair(bucket.value());
        for(;listPair.hasNext();listPair.next())
        {
            qDebug() << '\t' << listPair.value().first << " ( Distance =  " << listPair.value().second << " )\n";
        }
        qDebug() << "\t\t\t=======================================================================\n";
    }
}
