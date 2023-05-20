#include "graph.h"
#include "enumerators.cpp"

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
void graph::deleteRoad(QString city1, QString city2)
{
    // if at least one city doesn't exist
    if (!vertexExists(city1))
    {
        // cout << '\"' << city1 << "\" doesn't exist =|\n";
        return;
    }
    if (!vertexExists(city2))
    {
        // cout << '\"' << city2 << "\" doesn't exist =|\n";
        return;
    }

    // know the existing roads between the 2 cities
    bool road12 = edgeExists(city1, city2);
    bool road21 = edgeExists(city2, city1);

    // no roads
    if(!road12 && !road21)
    {
        // cout << "There is no road between " << city1 << " and " << city2 << " =(\n";
        return;
    }

    // one road city1 -> city2
    if (road12 && !road21)
    {
        deleteEdge(city1, city2);
        return;
    }

    // one road city2 -> city1
    if (!road12 && road21)
    {
        deleteEdge(city2, city1);
        return;
    }

    // reaching here means there is a 2-way road

    bool sameDistance = getEdgeWeight(city1, city2) == getEdgeWeight(city2, city1);
    if (sameDistance)
    {
        deleteEdge(city1, city2);
        deleteEdge(city2, city1);
        return;
    }
    else
    {
        int choice = 0;
        while (true)
        {
            /*
            cout << "1- delete road from " << city1 << " to " << city2 << "\n"
                 << "2- delete road from " << city2 << " to " << city1 << "\n"
                 << "3- delete  both roads \n";
            cin >> choice;
            */

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
                // cout << "Invalid choice!  Try agian\n";
                continue;
            }
            break;
        }
    }


    // cout << "Road is deleted\n";
    return;
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
void graph:: deleteCity(QString cityName)
{
    if (!vertexExists(cityName))
    {
        // qDebug() << "city " << cityName << " does not exist.. I can't delete it =(\n";
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
            if(getEdgeWeight(cityName, listPair.value().first) != getEdgeWeight(listPair.value().first, cityName))
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

    // qDebug() << "City is deleted\n";
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

// Others
void graph:: display()
{
    //qDebug() << "\n\tMap Cities:";
    QMutableHashIterator <QString , QList<QPair<QString, float>>> bucket(map);

    for(;bucket.hasNext();bucket.next())
    {
        //qDebug() << "\nCity: " << bucket.key();

        QMutableListIterator <QPair<QString, float>> listPair(bucket.value());
        for(;listPair.hasNext();listPair.next())
        {
            //qDebug() << '\t' << listPair.value().first << " ( Distance =  " << listPair.value().second << " )\n";
        }
        //qDebug() << "\t\t\t=======================================================================\n";
    }
}
