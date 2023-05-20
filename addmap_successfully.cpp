#include "addmap_successfully.h"
#include "ui_addmap_successfully.h"
#include <QPixmap>
#include "homepage.h"
#include "addmap.h"


HomePage* homepage_mapaddedObject;
addmap* returnaddmap_successObject;

addmap_successfully::addmap_successfully(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addmap_successfully)
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

    // Initialize the pointers
    homepage_mapaddedObject = nullptr;
    returnaddmap_successObject = nullptr;

}

addmap_successfully::~addmap_successfully()
{
    delete ui;
}

void addmap_successfully::on_pushButton_return_clicked()
{
    if (homepage_mapaddedObject == nullptr)
    {
        homepage_mapaddedObject = new HomePage; // Create a new instance if it doesn't exist
        homepage_mapaddedObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    homepage_mapaddedObject->show();
    this->hide();
}



void addmap_successfully::on_pushButton_addanother_clicked()
{
    if (returnaddmap_successObject == nullptr)
    {
        returnaddmap_successObject = new addmap; // Create a new instance if it doesn't exist
        returnaddmap_successObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    returnaddmap_successObject->show();
    this->hide();
}

