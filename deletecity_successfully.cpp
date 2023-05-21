#include "deletecity_successfully.h"
#include "ui_deletecity_successfully.h"
#include "update_menu.h"
#include "delete_city.h"

Update_menu* update_deletecitysuccess;
delete_city* returndeletecity_success;

DeleteCity_Successfully::DeleteCity_Successfully(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteCity_Successfully)
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

    update_deletecitysuccess = nullptr;
    returndeletecity_success = nullptr;
}

DeleteCity_Successfully::~DeleteCity_Successfully()
{
    delete ui;
}

void DeleteCity_Successfully::on_deletecity_success_addanoter_clicked()
{
    if (returndeletecity_success == nullptr)
    {
        returndeletecity_success = new delete_city; // Create a new instance if it doesn't exist
        returndeletecity_success->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returndeletecity_success->show();
    this->hide();
}


void DeleteCity_Successfully::on_deletecity_success_return_clicked()
{
    if (update_deletecitysuccess == nullptr)
    {
        update_deletecitysuccess = new Update_menu; // Create a new instance if it doesn't exist
        update_deletecitysuccess->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_deletecitysuccess->show();
    this->hide();
}

