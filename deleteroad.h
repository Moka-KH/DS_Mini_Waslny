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

private slots:
    void on_addROAD_addButton_clicked();

    void on_Returntoupdate_addROAD_clicked();

private:
    Ui::deleteRoad *ui;
};

#endif // DELETEROAD_H
