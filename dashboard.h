#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include "displaymapdata.h"
#include "traverse.h"
#include "pathfinder_main.h"
#include "update_menu.h"



class HomePage;
class DisplayMapData;
class traverse;
class PathFinder_Main;
class Update_menu;

namespace Ui {
class dashboard;
}

class dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit dashboard(QWidget *parent = nullptr);
    ~dashboard();

private slots:
    void on_returntohomepage_button_clicked();

    void on_displaymapdata_button_clicked();

    void on_traverse_button_clicked();

    void on_shortestpathfinder_button_clicked();

    void on_updatemapdata_button_clicked();

private:
    Ui::dashboard *ui;
    DisplayMapData* displaymapdata;
    traverse* traversedata;
    PathFinder_Main* pathfinder_main;
    Update_menu* update_menu;
};

#endif // DASHBOARD_H
