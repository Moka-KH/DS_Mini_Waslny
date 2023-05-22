#include "delete_city.h"
#include "enumerators.cpp"
#include "ui_delete_city.h"
#include "update_menu.h"
#include "deletecity_error.h"
#include "deletecity_successfully.h"
#include"gVariables.h"

Update_menu* updatemenureturnPointer;

delete_city::delete_city(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_city),
    citydeletedPointer(new DeleteCity_Successfully), // Initialize the pointer for mapadded
    deletecityerrorPointer(new DeleteCity_Error) // Initialize the pointer for error in adding map
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

    updatemenureturnPointer = nullptr;
}

delete_city::~delete_city()
{
    delete ui;
}

void delete_city::on_deleteCITY_deleteButton_clicked()
{
    QString cityName = ui->deleteCITY_lineedit->text();

    int message=currentGraph->deleteCity(cityName);
    if(message==Cdeleted)
    {
        this->hide(); // Close
        citydeletedPointer->show();
    }
    else if (message == cityNotExists)
    {
        this->hide(); // Close
        deletecityerrorPointer->show();
    }

}


void delete_city::on_Returntoupdate_deleteCITY_clicked()
{
    if (updatemenureturnPointer == nullptr)
    {
        updatemenureturnPointer = new Update_menu; // Create a new instance if it doesn't exist
        updatemenureturnPointer->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    updatemenureturnPointer->show();
    this->hide();
}

