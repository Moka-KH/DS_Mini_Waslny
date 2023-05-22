#ifndef GRAPH_H
#define GRAPH_H
#include<QList>
#include<QPair>
#include<QHash>


class graph
{
private:
    int vertexNum;
    int edgeNum;
public:
    QString name;
    QHash <QString, QList<QPair <QString, float>>> map;

    graph();
    graph(QString name);
    ~graph();

    // Getters
    int getVertexNum();
    int getEdgeNum();
    int getOutEdgesNumber(QString city1);
    float getEdgeWeight(QString city1, QString city2);

    QList<QPair<QString, float>> getOutAdjacents(QString city);
    QList<QPair<QString, float>> getInAdjacents(QString city);
    QList<QPair <QString, float>> getAdjacents(QString city);

    // Boolean Checkers
    bool vertexExists(QString city);
    bool edgeExists(QString city1,QString city2);
    bool empty();

    // Roads
    int addEditRoad(QString city1, QString city2, float distance);
    void deleteEdge(QString city1,QString city2);

    // Cities
    int addCity(QString city);
    int deleteCity(QString cityName);

    // Others
    QString  display();
};

#endif // GRAPH_H
