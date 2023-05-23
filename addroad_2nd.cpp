#include "addroad_2nd.h"
#include "gVariables.h"
#include"enumerators.cpp"
#include "ui_addroad_2nd.h"
#include "update_menu.h"

Update_menu* update_menu_2_returnPointer;

addroad_2nd::addroad_2nd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addroad_2nd)
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

    update_menu_2_returnPointer = nullptr;
}

addroad_2nd::~addroad_2nd()
{
    delete ui;
}

void addroad_2nd::on_addROAD_addButton_clicked()
{
    QString selectedItem = ui->AddRoad_direction->currentText();
    int outAdd=-1;

    // if the first city doesn't exist
    if (!currentGraph->vertexExists(city1AddRoad))
        ui->addROAD_messageLabel->setText(city1AddRoad+" Dosen't Exsist");

    else if (!currentGraph->vertexExists(city2AddRoad))
        ui->addROAD_messageLabel->setText(city2AddRoad+" Dosen't Exsist");

    else
    {
       if(selectedItem==ui->AddRoad_direction->itemText(0))
       {
        outAdd=currentGraph->addEditRoad(city1AddRoad,city2AddRoad,distanceAddRoad);
       }
       else if(selectedItem==ui->AddRoad_direction->itemText(1))
       {
        outAdd=currentGraph->addEditRoad(city2AddRoad,city1AddRoad,distanceAddRoad);
       }
       else if(selectedItem==ui->AddRoad_direction->itemText(2))
       {
        outAdd=currentGraph->addEditRoad(city1AddRoad,city2AddRoad,distanceAddRoad);
        outAdd=currentGraph->addEditRoad(city2AddRoad,city1AddRoad,distanceAddRoad);
       }

       if(outAdd==addedRoad)
       {
        ui->addROAD_messageLabel->setText("Road is added successfully ");
       }
       else if(outAdd==updatedRoad)
       {
        ui->addROAD_messageLabel->setText("Road is updated successfully ");
       }
    }

}


void addroad_2nd::on_Returntoupdate_addROAD_clicked()
{
    if (update_menu_2_returnPointer == nullptr)
    {
        update_menu_2_returnPointer = new Update_menu; // Create a new instance if it doesn't exist
        update_menu_2_returnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menu_2_returnPointer->show();
    this->hide();
}

