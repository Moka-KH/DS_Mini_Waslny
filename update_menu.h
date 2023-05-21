#ifndef UPDATE_MENU_H
#define UPDATE_MENU_H

#include "addcity.h"
#include "addroad.h"
#include "deleteroad.h"
#include "delete_city.h"

#include <QWidget>

class addcity;
class AddRoad;
class deleteRoad;
class delete_city;

namespace Ui {
class Update_menu;
}

class Update_menu : public QWidget
{
    Q_OBJECT

public:
    explicit Update_menu(QWidget *parent = nullptr);
    ~Update_menu();

private slots:
    void on_returntohomepage_button_clicked();

    void on_addcity_button_clicked();

    void on_add_edit_road_button_clicked();

    void on_deletecity_button_clicked();

    void on_deleteroad_button_clicked();

private:
    Ui::Update_menu *ui;

    addcity* addcityPointer;
    AddRoad* addroadPointer;
    deleteRoad* deleteroadPointer;
    delete_city* deletecityPointer;
};

#endif // UPDATE_MENU_H
