#include "choosemap.h"
#include "ui_choosemap.h"
#include "dashboard.h"
#include "homepage.h"
#include "graph.h"
#include "gVariables.h"
#include <QHash>
#include <QString>
#include <QComboBox>
#include <QPixmap>


HomePage* homepage_chooseObject;

choosemap::choosemap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choosemap),

    // Initialize the pointer in the constractor for the dashboard and the homepage
    dashboardObject(new dashboard)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/centered.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    //set items in comboBox
    QMutableHashIterator<QString, graph> bucket(maps);
    // if the map is not empty, put the iterator at its beginning
    if (bucket.hasNext())
    {
        bucket.next();
    }
    for (; bucket.hasNext(); bucket.next())
        ui->choosemap_comboBox->addItem(bucket.key());

    homepage_chooseObject = nullptr; // Initialize the pointer
}

choosemap::~choosemap()
{
    delete ui;
}


void choosemap::on_choosemap_3_clicked()
{

    QString selectedItem = ui->choosemap_comboBox->currentText();

    if (!selectedItem.isEmpty()) {
        this->hide();
        dashboardObject->show();
    }


    /* selectedItem = ui->choosemap_comboBox->currentText();

    if (!selectedItem.isEmpty())
    {
       this->hide();
       //logic to choose tha map
       QMutableHashIterator<QString, graph> bucket(maps);
       if (bucket.hasNext())
       {
           bucket.next();
       }
       for (; bucket.hasNext(); bucket.next())
       {
           if(ui->choosemap_comboBox->currentText()== bucket.key())
            {
                currentGraph= &bucket.value();
                dashboardObject->show();
            }
       }
    }*/
}

void choosemap::on_addmaperror_return_2_clicked()
{
    if (homepage_chooseObject == nullptr)
    {
        homepage_chooseObject = new HomePage; // Create a new instance if it doesn't exist
        homepage_chooseObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    homepage_chooseObject->show();
    this->hide();
}
