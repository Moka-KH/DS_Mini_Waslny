#include "addroad.h"
#include "ui_addroad.h"
#include "update_menu.h"
#include "addroad_2nd.h"
#include"gVariables.h"

Update_menu* update_menu_returnPointer;

AddRoad::AddRoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddRoad),
    step2ofaddroad(new addroad_2nd)
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

    update_menu_returnPointer = nullptr;
}

AddRoad::~AddRoad()
{
    delete ui;
}

void AddRoad::on_addROAD_addButton_clicked()
{
    city1AddRoad = ui->addROAD_city1->text();
    city2AddRoad = ui->addROAD_city2->text();
    distanceAddRoad = ui->addROAD_distance->text().toFloat();
    step2ofaddroad->show();
    this->hide();
}


void AddRoad::on_Returntoupdate_addROAD_clicked()
{
    if (update_menu_returnPointer == nullptr)
    {
        update_menu_returnPointer = new Update_menu; // Create a new instance if it doesn't exist
        update_menu_returnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menu_returnPointer->show();
    this->hide();
}

