#ifndef PATHFINDER_MAIN_H
#define PATHFINDER_MAIN_H

#include <QWidget>

#include "twocities_path.h"
#include "threecities_path.h"
#include "fourcities_path.h"
#include "fivecities_path.h"
#include "sixcities_path.h"
#include "sevencities_path.h"
#include "defaultcities_path.h"
#include "error_pathfinder.h"

class TwoCities_Path;
class ThreeCities_Path;
class FourCities_Path;
class FiveCities_Path;
class SixCities_Path;
class SevenCities_Path;
class DefaultCities_Path;
class Error_PathFinder;


namespace Ui {
class PathFinder_Main;
}

class PathFinder_Main : public QWidget
{
    Q_OBJECT

public:
    explicit PathFinder_Main(QWidget *parent = nullptr);
    ~PathFinder_Main();

private slots:
    void on_addmap_add_clicked();

    void on_addmap_add_2_clicked();

private:
    Ui::PathFinder_Main *ui;

    TwoCities_Path* twocities_path;
    ThreeCities_Path*threecities_path;
    FourCities_Path* fourcities_path;
    FiveCities_Path* fivecities_path;
    SixCities_Path* sixcities_path;
    SevenCities_Path* sevencities_path;
    DefaultCities_Path* defaultcities_path;
    Error_PathFinder*  error_pathfinder;
};

#endif // PATHFINDER_MAIN_H
