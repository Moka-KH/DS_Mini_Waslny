#ifndef ADDROAD_H
#define ADDROAD_H

#include <QWidget>

#include "addroad_2nd.h"

class addroad_2nd;

namespace Ui {
class AddRoad;
}

class AddRoad : public QWidget
{
    Q_OBJECT

public:
    explicit AddRoad(QWidget *parent = nullptr);
    ~AddRoad();

private slots:
    void on_addROAD_addButton_clicked();

    void on_Returntoupdate_addROAD_clicked();

private:
    Ui::AddRoad *ui;

    addroad_2nd* step2ofaddroad;
};

#endif // ADDROAD_H
