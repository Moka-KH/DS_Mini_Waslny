#include "dashboard.h"
#include "ui_dashboard.h"
#include "homepage.h"
#include "displaymapdata.h"
#include "traverse.h"
#include "pathfinder_main.h"
#include "update_menu.h"


HomePage* homepage_dashboardObject;

dashboard::dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dashboard),

    // Initialize the pointer in the constractor of the class to be used in showing the windows
    displaymapdata(new DisplayMapData),
    traversedata(new traverse),
    pathfinder_main(new PathFinder_Main),
    update_menu(new Update_menu)
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

    homepage_dashboardObject = nullptr; // Initialize the pointer
}

dashboard::~dashboard()
{
    delete ui;
}

void dashboard::on_returntohomepage_button_clicked()
{
    if (homepage_dashboardObject == nullptr)
    {
        homepage_dashboardObject = new HomePage; // Create a new instance if it doesn't exist
        homepage_dashboardObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    homepage_dashboardObject->show();
    this->hide();
}


void dashboard::on_displaymapdata_button_clicked()
{
    displaymapdata->show();
    this->hide();
}


void dashboard::on_traverse_button_clicked()
{
    traversedata->show();
    this->hide();
}


void dashboard::on_shortestpathfinder_button_clicked()
{
    pathfinder_main->show();
    this->hide();
}


void dashboard::on_updatemapdata_button_clicked()
{
    update_menu->show();
    this->hide();
}

