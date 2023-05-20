#include "newmap_created.h"
#include "ui_newmap_created.h"
#include <QPixmap>

NewMapLoader::NewMapLoader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewMapLoader)
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


}

NewMapLoader::~NewMapLoader()
{
    delete ui;
}
