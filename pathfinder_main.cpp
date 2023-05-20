#include "pathfinder_main.h"
#include "ui_pathfinder_main.h"
#include "dashboard.h"
#include "twocities_path.h"
#include "threecities_path.h"
#include "fourcities_path.h"
#include "fivecities_path.h"
#include "sixcities_path.h"
#include "sevencities_path.h"
#include "defaultcities_path.h"
#include "error_pathfinder.h"

#include <QPixmap>
#include <QVector>

#include"graph.h"
#include "algorithms.h"
#include<QPair>
#include<QStack>

dashboard* dashboard_mainfinderreturnObject;

PathFinder_Main::PathFinder_Main(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PathFinder_Main),
    twocities_path(new TwoCities_Path),
    threecities_path(new ThreeCities_Path),
    fourcities_path(new FourCities_Path),
    fivecities_path(new FiveCities_Path),
    sixcities_path(new SixCities_Path),
    sevencities_path(new SevenCities_Path),
    defaultcities_path(new DefaultCities_Path),
    error_pathfinder(new Error_PathFinder)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Half-Half.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_mainfinderreturnObject = nullptr;

}

PathFinder_Main::~PathFinder_Main()
{
    delete ui;
}

//find the shortest path button
void PathFinder_Main::on_addmap_add_clicked()
{
    graph myGraph;
    QString city1 = ui->addmap_lineedit->text();
    QString city2 = ui->addmap_lineedit_3->text();
    QStack<QPair<QString, float>> path;
    float distance = Dijkstra(myGraph,city1,city2,path);

    // shortest path display based on the vector size..
    if(path.empty()){
        error_pathfinder->show();
        this->hide();
    }
    else if(path.size()==2){
        twocities_path->show();
        this->hide();
    }
    else if (path.size()==3){
        threecities_path->show();
        this->hide();
    }
    else if (path.size()==4){
        fourcities_path->show();
        this->hide();
    }
    else if (path.size()==5){
        fivecities_path->show();
        this->hide();
    }
    else if (path.size()==6){
        sixcities_path->show();
        this->hide();
    }
    else if (path.size()==7){
        sevencities_path->show();
        this->hide();
    }
    else
    {
        defaultcities_path->show();
        this->hide();
    }
}

//Return to the dashboard button
void PathFinder_Main::on_addmap_add_2_clicked()
{
    if (dashboard_mainfinderreturnObject == nullptr)
    {
        dashboard_mainfinderreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_mainfinderreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_mainfinderreturnObject->show();
    this->hide();
}

