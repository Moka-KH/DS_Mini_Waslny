#ifndef UPDATE_MENU_H
#define UPDATE_MENU_H

#include "addcity.h"

#include <QWidget>

class addcity;

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
};

#endif // UPDATE_MENU_H
