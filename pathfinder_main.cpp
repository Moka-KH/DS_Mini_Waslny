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
#include"gVariables.h"
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

    /*currentGraph->addCity("A");
    currentGraph->addCity("B");
    currentGraph->addCity("C");
    currentGraph->addCity("D");
    currentGraph->addCity("E");
    currentGraph->addCity("F");


    currentGraph->addEditRoad("A", "B", 2);
    currentGraph->addEditRoad("A", "C", 4);
    currentGraph->addEditRoad("B", "C", 1);
    currentGraph->addEditRoad("B", "E", 2);
    currentGraph->addEditRoad("B", "D", 4);
    currentGraph->addEditRoad("C", "E", 3);
    currentGraph->addEditRoad("E", "D", 3);
    currentGraph->addEditRoad("E", "F", 2);
    currentGraph->addEditRoad("D", "F", 3);*/

    dashboard_mainfinderreturnObject = nullptr;

}

PathFinder_Main::~PathFinder_Main()
{
    delete ui;
}

//find the shortest path button
void PathFinder_Main::on_addmap_add_clicked()
{

    fivecities_path->show();
    this->hide();
    /*startingVertex = ui->addmap_lineedit->text();
    targetVertex = ui->addmap_lineedit_3->text();
    if(!currentGraph->vertexExists(startingVertex) ||!currentGraph->vertexExists(targetVertex))
    {
        error_pathfinder->show();
        this->hide();
    }
    totalDistance = Dijkstra(*currentGraph,startingVertex,targetVertex,path);
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
    }*/
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

