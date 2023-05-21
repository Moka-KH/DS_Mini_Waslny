#include "twocities_path.h"
#include "ui_twocities_path.h"
#include "dashboard.h"
#include"gVariables.h"

dashboard* dashboard_twocitiesreturnObject;

TwoCities_Path::TwoCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/2_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    // Set the cities names to the data from dijkstra to labels
    if(path.empty())
    {
        ui->city1_label->setText("path is empty");
    }
    else{
    ui->city1_label->setText(startingVertex);
    path.pop();

    ui->city2_label->setText(targetVertex);
    ui->distanse_between_label->setText(QString::number(totalDistance));
    path.pop();

    ui->shortestdistance->setText("The shortest distance between " + startingVertex + " and " + targetVertex + " is: " + QString::number(totalDistance));
    }
    dashboard_twocitiesreturnObject = nullptr; // Initialize the pointer
}

TwoCities_Path::~TwoCities_Path()
{
    delete ui;
}

void TwoCities_Path::on_traverse_button_clicked()
{
    if (dashboard_twocitiesreturnObject == nullptr)
    {
        dashboard_twocitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_twocitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_twocitiesreturnObject->show();
    this->hide();
}

