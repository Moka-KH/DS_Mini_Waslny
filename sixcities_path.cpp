#include "sixcities_path.h"
#include "ui_sixcities_path.h"
#include "dashboard.h"
#include"gVariables.h"

dashboard* dashboard_sixcitiesreturnObject;

SixCities_Path::SixCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SixCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/6_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    // Set the text of the label
    if(path.empty())
    {
        ui->city1_label->setText("path is empty");
    }
    else{
        ui->city1_label->setText(startingVertex);

        ui->distanse_between_label_1->setText(QString::number(path.top().second));
        ui->city2_label->setText(path.top().first);

        path.pop();

        ui->distanse_between_label_2->setText(QString::number(path.top().second));
        ui->city3_label->setText(path.top().first);

        path.pop();

        ui->distanse_between_label_3->setText(QString::number(path.top().second));
        ui->city4_label->setText(path.top().first);

        path.pop();

        ui->distanse_between_label_4->setText(QString::number(path.top().second));
        ui->city5_label->setText(path.top().first);

        path.pop();

        ui->distanse_between_label_5->setText(QString::number(path.top().second));
        ui->city6_label->setText(path.top().first);

        path.pop();

        ui->shortestdistance->setText("The shortest distance between " + startingVertex + " and " + targetVertex + " is: " + QString::number(totalDistance));
    }

    dashboard_sixcitiesreturnObject = nullptr; // Initialize the pointer
}

SixCities_Path::~SixCities_Path()
{
    delete ui;
}

void SixCities_Path::on_return_button_clicked()
{
    if (dashboard_sixcitiesreturnObject == nullptr)
    {
        dashboard_sixcitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_sixcitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_sixcitiesreturnObject->show();
    this->hide();
}

