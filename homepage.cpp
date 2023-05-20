#include "homepage.h"
#include "ui_homepage.h"
#include "addmap.h"
#include "choosemap.h"
#include <QPixmap>
HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage),

    // Initialize the pointer
    addmapObject(new addmap),
    choosemapObject(new choosemap)
{

    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/home_page.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_pushButton_addnewmap_clicked()
{hide();
    addmapObject->show();
}


void HomePage::on_pushButton_mapdashboard_clicked()
{
    hide(); // Close
    choosemapObject->show();
}


void HomePage::on_pushButton_exit_clicked()
{
    exitloader.show(); // Show the exitloader window
    hide(); // Close the Mini_Wasalni_GUI window
}

