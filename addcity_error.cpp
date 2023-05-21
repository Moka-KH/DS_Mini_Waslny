#include "addcity_error.h"
#include "ui_addcity_error.h"
#include "update_menu.h"
#include "addcity.h"

Update_menu* update_cityerror;
addcity* returnaddcity_error;

AddCity_Error::AddCity_Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCity_Error)
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

    update_cityerror = nullptr;
    returnaddcity_error = nullptr;

}

AddCity_Error::~AddCity_Error()
{
    delete ui;
}

void AddCity_Error::on_addcity_error_addanoter_clicked()
{
    if (returnaddcity_error == nullptr)
    {
        returnaddcity_error = new addcity; // Create a new instance if it doesn't exist
        returnaddcity_error->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returnaddcity_error->show();
    this->hide();
}


void AddCity_Error::on_addcity_error_return_clicked()
{
    if (update_cityerror == nullptr)
    {
        update_cityerror = new Update_menu; // Create a new instance if it doesn't exist
        update_cityerror->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_cityerror->show();
    this->hide();

}

