#ifndef DELETEROAD_H
#define DELETEROAD_H

#include <QWidget>

namespace Ui {
class deleteRoad;
}

class deleteRoad : public QWidget
{
    Q_OBJECT

public:
    explicit deleteRoad(QWidget *parent = nullptr);
    ~deleteRoad();

private:
    Ui::deleteRoad *ui;
};

#endif // DELETEROAD_H
