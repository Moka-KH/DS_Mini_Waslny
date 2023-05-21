#ifndef ADDROAD_H
#define ADDROAD_H

#include <QWidget>

namespace Ui {
class AddRoad;
}

class AddRoad : public QWidget
{
    Q_OBJECT

public:
    explicit AddRoad(QWidget *parent = nullptr);
    ~AddRoad();

private:
    Ui::AddRoad *ui;
};

#endif // ADDROAD_H
