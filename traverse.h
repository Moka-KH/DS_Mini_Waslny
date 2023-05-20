#ifndef TRAVERSE_H
#define TRAVERSE_H

#include <QWidget>

#include "dfs.h"
#include "bfs.h"

class DFS;
class BFS;

namespace Ui {
class traverse;
}

class traverse : public QWidget
{
    Q_OBJECT

public:
    explicit traverse(QWidget *parent = nullptr);
    ~traverse();

private slots:
    void on_dfstraverse_button_clicked();
    void on_bfstraverse_button_clicked();

private:
    Ui::traverse *ui;
    DFS* dfstraverse;
    BFS* dfstraversal;
};

#endif // TRAVERSE_H
