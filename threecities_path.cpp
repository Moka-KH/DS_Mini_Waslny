#include "threecities_path.h"
#include "ui_threecities_path.h"
#include "dashboard.h"
#include"gVariables.h"

dashboard* dashboard_threecitiesreturnObject;

ThreeCities_Path::ThreeCities_Path(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThreeCities_Path)
{
    ui->setupUi(this);

    // Load the background image
    QPixmap backgroundImage(":/resources/Pictures/3_cities_path.png");
    // Set the background image as the widget's palette background
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
    this->setPalette(palette);

    // Load the icon image
    QPixmap iconImage(":/resources/Pictures/Icon.png"); // Replace "path_to_icon_file.ico" with the actual path to your icon file
    // Set the icon for the window
    setWindowIcon(QIcon(iconImage));

    // Set the text of the label
    ui->city1_label->setText(startingVertex);

    ui->distanse_between_label_1->setText(QString::number(path.top().second));
    ui->city2_label->setText(path.top().first);

    path.pop();

    ui->distanse_between_label_2->setText(QString::number(path.top().second));
    ui->city3_label->setText(path.top().first);

    path.pop();

    ui->shortestdistance->setText("The shortest distance between " + startingVertex + " and " + targetVertex + " is: " + QString::number(totalDistance));


    dashboard_threecitiesreturnObject = nullptr; // Initialize the pointer
}

ThreeCities_Path::~ThreeCities_Path()
{
    delete ui;
}

void ThreeCities_Path::on_return_button_clicked()
{
    if (dashboard_threecitiesreturnObject == nullptr)
    {
        dashboard_threecitiesreturnObject = new dashboard; // Create a new instance if it doesn't exist
        dashboard_threecitiesreturnObject->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
    }
    dashboard_threecitiesreturnObject->show();
    this->hide();
}

