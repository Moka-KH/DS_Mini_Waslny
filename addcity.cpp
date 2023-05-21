#include "addcity.h"
#include "ui_addcity.h"
#include "enumerators.cpp"
#include"gVariables.h"

addcity::addcity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addcity)
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
        hide(); // Close
        //->show();
    }
    else if (message == success)
    {
        hide(); // Close
        //->show()
    }


}


void addcity::on_Returntoupdate_addcity_clicked()
{

}
