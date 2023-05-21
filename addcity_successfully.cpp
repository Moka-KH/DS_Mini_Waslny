#include "addcity_successfully.h"
#include "ui_addcity_successfully.h"

#include "update_menu.h"
#include "addcity.h"

Update_menu* update_citysuccess;
addcity* returnaddcity_success;

AddCity_Successfully::AddCity_Successfully(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddCity_Successfully)
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

    update_citysuccess = nullptr;
    returnaddcity_success = nullptr;
}

AddCity_Successfully::~AddCity_Successfully()
{
    delete ui;
}

void AddCity_Successfully::on_addcity_success_addanoter_clicked()
{
    if (returnaddcity_success == nullptr)
    {
        returnaddcity_success = new addcity; // Create a new instance if it doesn't exist
        returnaddcity_success->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returnaddcity_success->show();
    this->hide();
}


void AddCity_Successfully::on_addcity_success_return_clicked()
{
    if (update_citysuccess == nullptr)
    {
        update_citysuccess = new Update_menu; // Create a new instance if it doesn't exist
        update_citysuccess->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_citysuccess->show();
    this->hide();
}

