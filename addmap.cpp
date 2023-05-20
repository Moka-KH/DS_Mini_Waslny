#include "addmap.h"
#include "ui_addmap.h"
#include "homepage.h"
#include "addmap_successfully.h"
#include "addmap_error.h"

#include <QString>
#include <QLineEdit>



HomePage* homepageObject;

addmap::addmap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addmap),
    mapaddedObject(new addmap_successfully), // Initialize the pointer for mapadded
    addmaperrorObject(new addmap_error) // Initialize the pointer for error in adding map
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

    homepageObject = nullptr; // Initialize the pointer
}

addmap::~addmap()
{
    delete ui;
}


// return to the homepage
void addmap::on_addmap_add_2_clicked()
{
    if (homepageObject == nullptr)
    {
        homepageObject = new HomePage; // Create a new instance if it doesn't exist
        homepageObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    homepageObject->show();
    this->hide();
}

//create new map
void addmap::on_addmap_add_clicked()
{
    QString answer = ui->addmap_lineedit->text();

    if (answer.toLower() == "yes")
    {
        this->hide();
        mapaddedObject->show();
    }
    else
    {
        this->hide();
        addmaperrorObject->show();
    }
}


