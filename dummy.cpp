#include "dummy.h"
#include "ui_dummy.h"
#include "dashboard.h"

#include <QString>
#include <QComboBox>
#include <QPixmap>

choosemap::choosemap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosemap),

    // Initialize the pointer in the constractor for the dashboard and the homepage
    dashboardObject(new dashboard)
{
    ui->setupUi(this);


    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/choose Map.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));
}

choosemap::~choosemap()
{
    delete ui;
}


//void choosemap::on_choosemap_2_clicked()
//{
////    QString selectedItem = ui->choosemap_comboBox->currentText();

////    if (!selectedItem.isEmpty()) {
////        this->hide();
////        dashboardObject->show();
////    }
//    this->hide();
//    dashboardObject->show();
//}




