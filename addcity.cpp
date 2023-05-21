#include "addcity.h"
#include "ui_addcity.h"
#include "enumerators.cpp"
#include"gVariables.h"
#include "update_menu.h"

#include "addcity_error.h"
#include "addcity_successfully.h"

Update_menu* update_menu_returnObject;

addcity::addcity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addcity),
    cityaddedPointer(new AddCity_Successfully), // Initialize the pointer for mapadded
    addcityerrorPointer(new AddCity_Error) // Initialize the pointer for error in adding map
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

    update_menu_returnObject = nullptr;
}

addcity::~addcity()
{
    delete ui;
}

void addcity::on_addCITY_add_clicked()
{
    QString cityName=ui->addCITY_lineedit->text();

    int message=currentGraph->addCity(cityName);
    if(message==cityExists)
    {
        this->hide(); // Close
        addcityerrorPointer->show();
    }
    else if (message == success)
    {
        this->hide(); // Close
        cityaddedPointer->show();
    }
}

void addcity::on_Returntoupdate_addcity_clicked()
{
    if (update_menu_returnObject == nullptr)
    {
        update_menu_returnObject = new Update_menu; // Create a new instance if it doesn't exist
        update_menu_returnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_menu_returnObject->show();
    this->hide();
}
