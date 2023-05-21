#include "welcome.h"
#include "ui_welcome.h"
#include <QPixmap>
#include "homepage.h"
#include"files.h"
#include"gVariables.h"

welcome::welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcome)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/Welcome.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));
}

welcome::~welcome()
{
    delete ui;
}

void welcome::on_pushButton_clicked()
{
    homepage.show(); // Show the homepage window
    QString helperString = QString::fromLocal8Bit(".\\");
    maps = readMultipleGraphs(helperString);
    close(); // Close the Mini_Wasalni_GUI window
}

