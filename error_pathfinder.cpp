#include "error_pathfinder.h"
#include "ui_error_pathfinder.h"
#include "dashboard.h"
#include "pathfinder_main.h"

dashboard* dashboard_errorreturnObject;
PathFinder_Main* pathfinder_main_Object;

Error_PathFinder::Error_PathFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error_PathFinder)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Title.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    dashboard_errorreturnObject = nullptr;
    pathfinder_main_Object = nullptr;
}

Error_PathFinder::~Error_PathFinder()
{
    delete ui;
}

//return to pathfinder
void Error_PathFinder::on_pathfinder_another_clicked()
{
    if (pathfinder_main_Object == nullptr)
    {
        pathfinder_main_Object = new PathFinder_Main; // Create a new instance if it doesn't exist
        pathfinder_main_Object->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    pathfinder_main_Object->show();
    this->hide();
}

//return to dashboard
void Error_PathFinder::on_pathfindererror_return_clicked()
{
    if (dashboard_errorreturnObject == nullptr)
    {
        dashboard_errorreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_errorreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_errorreturnObject->show();
    this->hide();
}

