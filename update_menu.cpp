#include "update_menu.h"
#include "ui_update_menu.h"
#include "dashboard.h"
#include "addcity.h"

#include <QPixmap>
#include <QPalette>
#include <QIcon>
#include <QBrush>


dashboard* dashboard_updatereturnObject;

Update_menu::Update_menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update_menu),
    addcityPointer(new addcity)
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
    dashboard_updatereturnObject = nullptr;
}

Update_menu::~Update_menu()
{
    delete ui;
}

//return to dahboard button
void Update_menu::on_returntohomepage_button_clicked()
{
    if (dashboard_updatereturnObject == nullptr)
    {
        dashboard_updatereturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_updatereturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_updatereturnObject->show();
    this->hide();
}


void Update_menu::on_addcity_button_clicked()
{
    addcityPointer->show();
    this->hide();
}


void Update_menu::on_add_edit_road_button_clicked()
{

}


void Update_menu::on_deletecity_button_clicked()
{

}


void Update_menu::on_deleteroad_button_clicked()
{

}

