#include "addmap_error.h"
#include "ui_addmap_error.h"
#include "homepage.h"
#include "addmap.h"

HomePage* homepage_maperrorObject;
addmap* returnaddmap_errorObject;

addmap_error::addmap_error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addmap_error)
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

    // Initialize the pointer
    homepage_maperrorObject = nullptr;
    returnaddmap_errorObject = nullptr;
}

addmap_error::~addmap_error()
{
    delete ui;
}

void addmap_error::on_addmaperror_return_clicked()
{
    if (homepage_maperrorObject == nullptr)
    {
        homepage_maperrorObject = new HomePage; // Create a new instance if it doesn't exist
        homepage_maperrorObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    homepage_maperrorObject->show();
    this->hide();
}


void addmap_error::on_addmaperror_addanother_clicked()
{
    if (returnaddmap_errorObject == nullptr)
    {
        returnaddmap_errorObject = new addmap; // Create a new instance if it doesn't exist
        returnaddmap_errorObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returnaddmap_errorObject->show();
    this->hide();
}

