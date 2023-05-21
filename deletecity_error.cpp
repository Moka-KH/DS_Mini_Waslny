#include "deletecity_error.h"
#include "ui_deletecity_error.h"
#include "update_menu.h"
#include "delete_city.h"

Update_menu* update_deletecityerror;
delete_city* returndeletecity_error;


DeleteCity_Error::DeleteCity_Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteCity_Error)
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

    update_deletecityerror = nullptr;
    returndeletecity_error = nullptr;
}

DeleteCity_Error::~DeleteCity_Error()
{
    delete ui;
}

void DeleteCity_Error::on_deletecity_error_addanoter_clicked()
{
    if (returndeletecity_error == nullptr)
    {
        returndeletecity_error = new delete_city; // Create a new instance if it doesn't exist
        returndeletecity_error->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returndeletecity_error->show();
    this->hide();
}

void DeleteCity_Error::on_deletecity_error_return_clicked()
{
    if (update_deletecityerror == nullptr)
    {
        update_deletecityerror = new Update_menu; // Create a new instance if it doesn't exist
        update_deletecityerror->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    update_deletecityerror->show();
    this->hide();
}

