#include "deleteroad.h"
#include "ui_deleteroad.h"
#include "update_menu.h"
#include"gVariables.h"
#include"enumerators.cpp"

Update_menu* update_menureturnPointer;

deleteRoad::deleteRoad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteRoad)
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

    update_menureturnPointer =nullptr;
}

deleteRoad::~deleteRoad()
{
    delete ui;
}

void deleteRoad::on_addROAD_addButton_clicked()
{
    QString city1Name=ui->addROAD_city1->text();
    QString city2Name=ui->addROAD_city2->text();

    QString selectedItem = ui->AddRoad_direction->currentText();
    // know the existing roads between the 2 cities
    bool road12 = currentGraph->edgeExists(city1Name, city2Name);
    bool road21 = currentGraph->edgeExists(city2Name, city1Name);

    if (!currentGraph->vertexExists(city1Name))
    {
        ui->addROAD_errorLabel->setText(city1Name+ " Doesn't Esist");
    }
    if (!currentGraph->vertexExists(city2Name))
    {
        ui->addROAD_errorLabel->setText(city2Name+ " Doesn't Esist");
    }
    else{
      if(selectedItem==ui->AddRoad_direction->itemText(0))
      {
        if(!road12 && !road21)
        {
            ui->addROAD_errorLabel->setText("There is no road between two cities");
        }
        else if (road21 && !road12)
        {
            ui->addROAD_errorLabel->setText("There is only one road from "+city2Name+" to "+city1Name);
        }
        else
        {
            currentGraph->deleteEdge(city1Name, city2Name);
            ui->addROAD_errorLabel->setText("The road is deleted successfully");

        }
       }
      else if(selectedItem==ui->AddRoad_direction->itemText(1))
      {
        if(!road12 && !road21)
        {
            ui->addROAD_errorLabel->setText("There is no road between two cities");
        }
        else if (road12 && !road21)
        {
            ui->addROAD_errorLabel->setText("There is only one road from "+city1Name+" to "+city2Name);
        }
        else
        {
            currentGraph->deleteEdge(city2Name, city1Name);
            ui->addROAD_errorLabel->setText("The road is deleted successfully");

        }
      }
      else if(selectedItem==ui->AddRoad_direction->itemText(2))
      {
        if(road12 == false && road21== false)
        {
            ui->addROAD_errorLabel->setText("There is no road between two cities");
        }
        else if (road12 && !road21)
        {
            ui->addROAD_errorLabel->setText("There is only one road from "+city1Name+" to "+city2Name);
        }
        else if (road21 && !road12)
        {
            ui->addROAD_errorLabel->setText("There is only one road from "+city2Name+" to "+city1Name);
        }
        else if(road12 && road21)
        {
            currentGraph->deleteEdge(city1Name, city2Name);
            currentGraph->deleteEdge(city2Name, city1Name);
            ui->addROAD_errorLabel->setText("The road is deleted successfully");
        }
      }
    }

}


void deleteRoad::on_Returntoupdate_addROAD_clicked()
{
    if (update_menureturnPointer == nullptr)
    {
        update_menureturnPointer = new Update_menu; // Create a new instance if it doesn't exist
        update_menureturnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menureturnPointer->show();
    this->hide();
}

