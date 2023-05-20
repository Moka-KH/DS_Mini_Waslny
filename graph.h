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
    QHash <QString, QList<QPair <QString, float>>> map;
    graph();
    int getVertexNum();

    QList<QPair<QString, float>> getOutAdjacents(QString city);
    QList<QPair<QString, float>> getInAdjacents(QString city);
    QList<QPair <QString, float>> getAdjacents(QString city);

    bool vertexExists(QString city);
    bool edgeExists(QString city1,QString city2);
    int addCity(QString city);
};

#endif // GRAPH_H
