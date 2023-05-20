#ifndef ADDNEWMAP_H
#define ADDNEWMAP_H

#include "addnewmap_successfully.h"
#include <QWidget>

namespace Ui {
class AddNewMap;
}

class AddNewMap : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewMap(QWidget *parent = nullptr);
    ~AddNewMap();

private slots:
    void on_addmap_add_clicked();

    void on_addmap_add_2_clicked();

private:
    Ui::AddNewMap *ui;
    addnewmap_successfully addnewmap_successfully;
};



#endif // ADDNEWMAP_H
