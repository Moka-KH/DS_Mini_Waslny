#ifndef BFS_H
#define BFS_H

#include <QWidget>

class dashboard;

namespace Ui {
class BFS;
}

class BFS : public QWidget
{
    Q_OBJECT

public:
    explicit BFS(QWidget *parent = nullptr);
    ~BFS();

private slots:
    void on_traverse_button_clicked();

private:
    Ui::BFS *ui;
};

#endif // BFS_H
