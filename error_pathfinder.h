#ifndef ERROR_PATHFINDER_H
#define ERROR_PATHFINDER_H

#include <QWidget>

namespace Ui {
class Error_PathFinder;
}

class Error_PathFinder : public QWidget
{
    Q_OBJECT

public:
    explicit Error_PathFinder(QWidget *parent = nullptr);
    ~Error_PathFinder();

private slots:
    void on_pathfinder_another_clicked();

    void on_pathfindererror_return_clicked();

private:
    Ui::Error_PathFinder *ui;
};

#endif // ERROR_PATHFINDER_H
