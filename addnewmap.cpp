#include "addnewmap.h"
#include "ui_addnewmap.h"
#include <QPixmap>
#include "homepage.h"

HomePage *homePageReturn;

AddNewMap::AddNewMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewMap)
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

AddNewMap::~AddNewMap()
{
    delete ui;
}

void AddNewMap::on_addmap_add_clicked()
{
    addnewmap_successfully.show();
     hide(); // Close the Mini_Wasalni_GUI window
}



void AddNewMap::on_addmap_add_2_clicked()
{
     hide();
    homePageReturn = new HomePage(this);
    homePageReturn->show();
}

